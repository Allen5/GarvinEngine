
#include <network/tcpclient.h>

using namespace GarvinEngine;
using namespace GarvinEngine::Network;

bool TCPClient::conn(std::string serverIP, uint16 serverPort, uint32 innerTime)
{
<<<<<<< HEAD

#if defined(_WIN32) || defined(_WIN64)
	WSADATA wsadata;
	int ret = WSAStartup(MAKEWORD(2, 2), &wsadata);
	if (ret != 0) {
		std::cout << "WSAStartup() failed. " << GetLastError() << std::endl;
		return false;
	}
#endif

	sockfd(socket(AF_INET, SOCK_STREAM, 0));
	if (sockfd() < 0) {
		std::cout << "socket() failed. " << GetLastError() << std::endl;
		return false;
	}

	sockaddr_in serveraddr;
	memset(&serveraddr, 0, sizeof(serveraddr));
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_port = htons(serverPort);
=======
#if defined(_WIN32) || defined(_WIN64)
  WSADATA wsdata;
  int32 ret = WSAStartup(MAKEWORD(2, 2), &wsadata);
  if (ret != 0) {
    std::cout<<"TCPClient::conn(). WSAStartup() failed. errno:"<<WSAGetLastError()<<std::endl;
    return false;
  }
#endif
  sockfd(socket(AF_INET, SOCK_STREAM, 0));
  if (sockfd() < 0) {
    //log sth
    return false;
  }

  sockaddr_in serveraddr;
  memset(&serveraddr, 0, sizeof(serveraddr));
  serveraddr.sin_family = AF_INET;
  serveraddr.sin_port = htons(port());
>>>>>>> 85286cd1e31c9b944676750c61a1b9ca1dff6d90

#if defined(_WIN32) || defined(_WIN64)
	serveraddr.sin_addr.S_un.S_addr = inet_addr(serverIP.c_str());
#else
<<<<<<< HEAD
	inet_pton(AF_INET, serverIP.c_str(), &serverAddr.sin_addr);
=======
	inet_pton(AF_INET, ip().c_str(), &serveraddr.sin_addr);
>>>>>>> 85286cd1e31c9b944676750c61a1b9ca1dff6d90
#endif //cross-platform address binding

	if (connect(sockfd(), (struct sockaddr*)&serveraddr, sizeof(serveraddr)) < 0) {
		//log sth
		std::cout << "connect() failed. " << GetLastError() << std::endl;
		return false;
	}

	//keep the host ip and port
	ip(serverIP);
	port(serverPort);

	return true;

}

void TCPClient::run()
{
	_init();

#if defined(_WIN32) || defined(_WIN64)

	FD_SET rset;

	//set listen fd
	FD_SET(sockfd(), &_clientset);

	for (;;) {//win-select

		rset = _clientset;
		int32 nready = select(sockfd() + 1, &rset, NULL, NULL, NULL);

		if (FD_ISSET(sockfd(), &rset)) {//acception connection
<<<<<<< HEAD
			Response* resp = _getResp();
=======
			Response* resp = _getResponse();
>>>>>>> 85286cd1e31c9b944676750c61a1b9ca1dff6d90
			process(resp);
			if (--nready <= 0) continue;
		}

	}

#else

	for (;;) {//endless loop

		int32 nready = poll(&_clientfd, sockfd() + 1, INFTIM);

		//accept connections
		if (_clientfd.revents & POLLRDNORM) {
<<<<<<< HEAD
			Response* resp = _getResp();
=======
			Response* resp = _getResponse();
>>>>>>> 85286cd1e31c9b944676750c61a1b9ca1dff6d90
			process(resp);
			if (--nready <= 0) continue;
		}

	}
#endif //windows use win-select while *nix use poll
}

void TCPClient::_init()
{
#if defined(_WIN32) || defined(_WIN64)
	FD_ZERO(&_clientset);
#else
	//make the first fd to be listen fd
	_clientfd.fd = sockfd();
	_clientfd.events = POLLRDNORM;
#endif //init poll fd

	memset(_buf, 0, MAX_BUF);
	_pos = 0;
}

<<<<<<< HEAD
Response* TCPClient::_getResp()
{
	int32 n = recv(sockfd(), _buf + _pos, MAX_BUF, 0);

	if (n < 0) {//handle connreset error

#if defined(_WIN32) || defined(_WIN64)
		FD_CLR(sockfd(), &_clientset);
#endif

		if (errno == ECONNRESET) { CLOSE(sockfd()); sockfd(-1); }
		else { /*log server read error*/ }
		return NULL;
	}
	else if (n == 0) {//handle client close event

#if defined(_WIN32) || defined(_WIN64)
		FD_CLR(sockfd(), &_clientset);
#endif

		//todo
		//should add close event handler and invoke it

		CLOSE(sockfd);
		//log client closed the connect
		sockfd(-1);
		return NULL;
	}

	return _packgeDeal(n);

	int8 buf[MAX_BUF] = { 0 };
	int32 n = recv(sockfd(), buf, MAX_BUF, 0);
=======
Response* TCPClient::_getResponse()
{
	int32 n = recv(sockfd(), _buf, MAX_BUF, 0);
>>>>>>> 85286cd1e31c9b944676750c61a1b9ca1dff6d90

	if (n < 0) {//handle connreset error
		if (errno == ECONNRESET) { CLOSE(sockfd()); sockfd(-1); }
		else { /*log error*/ }
		return NULL;
	}
	else if (n == 0) {//handle client close event
		CLOSE(sockfd());
		//log client closed the connect
		sockfd(-1);
		return NULL;
	}

	return _packageDeal(n);
}

Response* TCPClient::_packageDeal(int32 n)
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

	Response* resp = new Response(pack);
	return resp;
}
