
#include <network/tcpnonblockserver.h>
#include <util/logger.h>


using namespace GarvinEngine;
using namespace GarvinEngine::Network;
using namespace GarvinEngine::Util;

bool TCPNonblockServer::open()
{
	if (!_init()) return false;

#if defined(_WIN32) || defined(_WIN64)

	FD_SET rset;
	_maxfd = listenfd();

	//set listen fd
	FD_SET(listenfd(), &_clientset);

	sockaddr_in clientaddr;
	for (;;) {//win-select

		rset = _clientset;
		int32 nready = select(_maxfd + 1, &rset, NULL, NULL, NULL);

		if (FD_ISSET(listenfd(), &rset)) {//acception connection
			Session* session = _accept(clientaddr);
			addSession(session);
			_setfd(session->sockfd());
			if (--nready <= 0) continue;
		}

		for (int32 i = 0; i <= _maxindex; i++) { //recv message

			if (_clientfd[i] <= 0) continue;

			if (FD_ISSET(_clientfd[i], &rset)) {
				Session* session = getSessionBySockfd(_clientfd[i]);
				if (session == NULL) continue;

				Request* req = request(session->sockfd());
				if (req == NULL) continue;

				process(session, req);
				if (--nready <= 0) break;
			}

		}

	}

#else

	for (;;) {//endless loop

		int32 nready = poll(_clientfd, m_maxindex + 1, INFTIM);

		//accept connections
		if (_clientfd[0].revents & POLLRDNORM) {
			Session* session = _accept(clientaddr);
			addSession(session);
			_setfd(session->sockfd());
			if (--nready <= 0) continue;
		}

		//receive msg from one of the conn fds
		for (int32 i = 1; i <= _maxindex; i++) {
			if (_clientfd[i].fd <= 0) continue;

			if (_clientfd[i].revents & (POLLRDNORM | POLLERR)) {
				Session* session = getSessionBySockfd(_clientfd[i]);
				if (session == NULL) continue;

				Request* req = request(session->sockfd());
				if (req == NULL) continue;

				process(session, req);
				if (--nready <= 0) break;
			}
		}

	}

#endif //windows use win-select while *nix use poll

	return true;
}

bool TCPNonblockServer::_init()
{

	_maxfd = 0;
	_maxindex = 0;

	memset(_buf, 0, sizeof(_buf));
	_pos = 0;

	if (!_bind()) return false;

	//init clear
	memset(_clientfd, 0, sizeof(_clientfd));

#if defined(_WIN32) || defined(_WIN64)
	for (int i = 0; i < OPEN_MAX; i++) _clientfd[i] = -1;
	FD_ZERO(&_clientset);
#else
	//make the first fd to be listen fd
	_clientfd[0].fd = _listenfd;
	_clientfd[0].events = POLLRDNORM;

	for (int i = 1; i < OPEN_MAX; i++) _clientfd[i].fd = -1;
#endif //init poll fd

	return true;
}

void TCPNonblockServer::_setfd(int32 sockfd)
{
#if defined(_WIN32) || defined(_WIN64)
	FD_SET(sockfd, &_clientset);
	int32 i = 0;
	for (; i < OPEN_MAX; i++) {
		if (_clientfd[i] <= 0) { _clientfd[i] = sockfd; _maxindex = i; break; }
	}
#else
	//add to the m_clientfd
	int32 i = 0;
	for (i = 1; i<OPEN_MAX; i++) {
		if (_clientfd[i].fd <= 0) { _clientfd[i].fd = sockfd; _clientfd[i].events = POLLRDNORM; break; }
	}

#endif

	if (i == OPEN_MAX) { 
		/*log sth*/
		printf("too many connections\n"); 
		return; 
	}

#if defined(_WIN32) || defined(_WIN64)

	if (sockfd > _maxfd) _maxfd = sockfd;

#else
	//reset the m_maxindex
	if (i > _maxindex) _maxindex = i;
#endif
}

Request* TCPNonblockServer::request(SOCKET sockfd)
{
	//todo;
	int32 n = recv(sockfd, _buf + _pos, MAX_BUF, 0);

	if (n < 0) {//handle connreset error

#if defined(_WIN32) || defined(_WIN64)
		FD_CLR(sockfd, &_clientset);
#endif

		if (errno == ECONNRESET) { CLOSE(sockfd); sockfd = -1; }
		else { /*log server read error*/ }
		return NULL;
	}
	else if (n == 0) {//handle client close event

#if defined(_WIN32) || defined(_WIN64)
		FD_CLR(sockfd, &_clientset);
#endif

		//todo
		//should add close event handler and invoke it

		CLOSE(sockfd);
		//log client closed the connect
		sockfd = -1;
		return NULL;
	}

	return _packgeDeal(n);

}

void TCPNonblockServer::response(SOCKET sockfd, Response* resp)
{
	assert(resp);
	Package* pack = resp->serial();
	assert(pack);

	//should add pack header
	pack->protoid(resp->protoID());
	pack->addPackHeader();

	int32 ret = send(sockfd, pack->buf(), pack->getPackLen(), 0);
	if (ret != pack->getPackLen()) { /* log sth */ }
}

Request* TCPNonblockServer::_packgeDeal(int32 n)
{
	Package* pack = new Package(_buf);
	if ((uint32)n < pack->getHeadLen()) {//only get package head but no body
		_pos += n;
		delete pack;
		pack = NULL;
		return NULL;
	}

	if ((uint32)n < pack->getPackLen()) {//package was splited
		_pos += n;
		delete pack;
		pack = NULL;
		return NULL;
	}

	if ((uint32)n >= pack->getPackLen()) {//package was clinged or package was right size
		memset(_buf, 0, pack->getPackLen());
		_pos = 0;
	}

	if ((uint32)n > pack->getPackLen()) {//package was clinged
		memmove(_buf, _buf + pack->getPackLen(), n - pack->getPackLen());
		memset(_buf + pack->getPackLen(), 0, n - pack->getPackLen());
	}

	Request* request = new Request(pack);
	return request;
}

bool TCPNonblockServer::_bind()
{

#if defined(_WIN32) || defined(_WIN64)
	WSADATA wsadata;
	int ret = WSAStartup(MAKEWORD(2, 2), &wsadata);
	if (ret != 0) {
		LOG_ERROR("TCPNonblockServer::_bind. WSAStartup failed. errno:%d", ret);
		return false;
	}
#endif

	//bind address and listen on port
	listenfd(socket(AF_INET, SOCK_STREAM, 0));
	if (listenfd() < 0) {
		LOG_ERROR("TCPNonblockServer::_bind() socket failed.");
		return false;
	}
	
	sockaddr_in serverAddr;
	memset(&serverAddr, 0, sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(port());

#if defined(_WIN32) || defined(_WIN64)
	serverAddr.sin_addr.S_un.S_addr = inet_addr(host().c_str());
#else
	inet_pton(AF_INET, ip(), &serverAddr.sin_addr);
#endif //cross-platform address binding


	LOG_DEBUG("TCPNonblockServer::_bind() ip:%s, port:%d", host().c_str(), port());

	//bind address
	if (bind(listenfd(), (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) {
		LOG_ERROR("TCPNonblockServer::_bind() bind failed. errno:%d", WSAGetLastError());
		CLOSE(listenfd());
		return false;
	}

	//listen
	if (listen(listenfd(), backlog()) < 0) {
		LOG_ERROR("TCPNonblockServer::_bind() listen failed. errno:%d", WSAGetLastError());
		CLOSE(listenfd());
		return false;
	}

	return true;
}

Session* TCPNonblockServer::_accept(sockaddr_in& clientaddr)
{
	memset(&clientaddr, 0, sizeof(clientaddr));

#if defined(_WIN32) || defined(_WIN64)
	int len = sizeof(clientaddr);
#else
	socklen_t len = sizeof(clientaddr);
#endif
	int32 clientfd = accept(listenfd(), (struct sockaddr *)&clientaddr, &len);
	if (clientfd < 0) {
		//todo log sth
		return NULL;
	}

	Session* session = new Session();
	session->sockfd(clientfd);
	sessionID(sessionID() + 1);
	session->sid(sessionID());

	char *tmpbuf = inet_ntoa(clientaddr.sin_addr);
	session->ip(tmpbuf);
	delete tmpbuf;

	session->port(ntohs(clientaddr.sin_port));

	//todo login time;
	session->loginTime(0);
	return session;
}
