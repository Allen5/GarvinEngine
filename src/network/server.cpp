
#include <network/server.h>

using namespace GarvinEngine;
using namespace GarvinEngine::Network;


Server::Server()
: _host("")
, _port(0)
, _backlog(0)
{
  _handlers.clear();
  _session_manager = SessionManager::getInstance();
  _session_manager->init();
}

Server::~Server()
{

}

void GarvinEngine::Network::Server::config(std::string host, uint16 port, uint16 backlog)
{
  this->_host = host;
  this->_port = port;
  this->_backlog = backlog;
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

void Server::broadcast(std::vector<Session*>& sessions, Response* resp)
{
  std::vector<Session*>::iterator iter = sessions.begin();
  for (; iter != sessions.end(); iter++) response((*iter)->sockfd(), resp);
}

bool Server::kick(Session* session)
{
  bool ret = session->close();
  _session_manager->remove(session);
  return ret;
}

void Server::close()
{
  std::vector<Session*> sessions;
  _session_manager->list(sessions);

  std::vector<Session*>::iterator iter = sessions.begin();
  for (; iter != sessions.end(); iter++) kick(*iter);

  if (CLOSE(_listenfd) < 0) {
    perror("Server::close() close listenfd failed");
  }
  
#if defined(_WIN32) || defined(_WIN64)
	WSACleanup();
#endif //windows should cleanup the socket
}
