
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

Session* Server::getSessionBySockfd(int32 sockfd)
{
	std::map<uint64, Session*>::iterator iter = _sessions.begin();
	for (; iter != _sessions.end(); iter++) {
		if (iter->second->sockfd() == sockfd) return iter->second;
	}
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

	Response* resp = iter->second->handle(request);
	if (resp == NULL) return;

	resp->setProto(request->protoID());
	response(session->sockfd(), resp);
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

void Server::broadcast(std::vector<Session*>& sessions, Response* resp)
{
	std::vector<Session*>::iterator iter = sessions.begin();
	for (; iter != sessions.end(); iter++) response((*iter)->sockfd(), resp);
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

	if (CLOSE(_listenfd) < 0) { 
		//log sth;
	}

#if defined(_WIN32) || defined(_WIN64)
	WSACleanup();
#endif //windows should cleanup the socket
}
