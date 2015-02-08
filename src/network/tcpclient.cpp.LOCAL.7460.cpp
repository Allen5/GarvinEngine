
#include <network/tcpclient.h>

using namespace GarvinEngine;
using namespace GarvinEngine::Network;

bool TCPClient::conn(std::string serverIP, uint16 serverPort, uint32 innerTime)
{

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

#if defined(_WIN32) || defined(_WIN64)
	serveraddr.sin_addr.S_un.S_addr = inet_addr(serverIP.c_str());
#else
	inet_pton(AF_INET, serverIP.c_str(), &serverAddr.sin_addr);
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
			Response* resp = _getResp();
			process(resp);
			if (--nready <= 0) continue;
		}

	}

#else

	for (;;) {//endless loop

		int32 nready = poll(_clientfd, sockfd() + 1, INFTIM);

		//accept connections
		if (_clientfd.revents & POLLRDNORM) {
			Response* resp = _getResp();
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
}

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

	Package* pack = new Package(buf);
	Request* request = new Request(pack);
	return request;
}
