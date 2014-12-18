
#include <network/server.h>

using namespace GarvinEngine;
using namespace GarvinEngine::Network;


Server::Server()
: _host("")
, _port(0)
, _backlog(0)
, _sessionID(0)
{
	_sessions.clear();
	_handlers.clear();
}

Server::~Server()
{

}

void Server::addSession(Session* session)
{
	_sessions[session->sid()] = session;
}

Session* Server::getSession(uint64 sessionId)
{
	std::map<uint64, Session*>::iterator iter = _sessions.find(sessionId);
	if (iter != _sessions.end()) return iter->second;
	return NULL;
}

void Server::listSession(std::vector<Session*>& sessions)
{
	sessions.clear();
	std::map<uint64, Session*>::iterator iter = _sessions.begin();
	for (; iter != _sessions.end(); iter++) {
		sessions.push_back(iter->second);
	}
}

void Server::process(Session* session, Request* request)
{
	std::map<uint32, Handler*>::iterator iter = _handlers.find(request->protoID());
	if (iter == _handlers.end()) return ;

	Response* response = iter->second->handle(request);
	if (response == NULL) return;

	response->protoID(request->protoID());
	session->send(response);
}

void Server::on(uint32 protoId, Handler* handler)
{
	_handlers[protoId] = handler;
}

void Server::removeSession(uint64 sessionId)
{
	std::map<uint64, Session*>::iterator it = _sessions.find(sessionId);
	if (it == _sessions.end()) return;
	_sessions.erase(it);
}

void Server::broadcast(std::vector<Session*>& sessions, Response* response)
{
	std::vector<Session*>::iterator iter = sessions.begin();
	for (; iter != sessions.end(); iter++) (*iter)->send(response);
}

bool Server::kick(Session* session)
{
	removeSession(session->sid());
	return session->close();
}

void Server::close()
{
	std::map<uint64, Session*>::iterator iter = _sessions.begin();
	for (; iter != _sessions.end(); iter++) kick(iter->second);
}

bool Server::_bind()
{
	//bind address and listen on port
	_listenfd = socket(AF_INET, SOCK_STREAM, 0);
	if (_listenfd < 0) {
		//todo, log sth
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


	//bind address
	if (bind(_listenfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) {
		//todo, log sth
		closesocket(_listenfd);
		return false;
	}

	//listen
	if (listen(_listenfd, backlog()) < 0) {
		//todo, log sth
		closesocket(_listenfd);
		return false;
	}

	return true;
}

Session* Server::_accept(sockaddr_in& clientaddr)
{
	memset(&clientaddr, 0, sizeof(clientaddr));

#if defined(_WIN32) || defined(_WIN64)
	int len = sizeof(clientaddr);
#else
	socklen_t len = sizeof(clientaddr);
#endif
	int32 clientfd = accept(_listenfd, (struct sockaddr *)&clientaddr, &len);
	if (clientfd < 0) {
		//todo log sth
		return NULL;
	}

	Session* session = new Session();
	session->sockfd(clientfd);
	session->sid(_sessionID++);
	//todo, session->ip(clientaddr.sin_addr);
	session->port(ntohs(clientaddr.sin_port));
	//todo login time;
	return session;
}
