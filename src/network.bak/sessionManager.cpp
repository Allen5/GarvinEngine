
#include <network/sessionManager.h>

using namespace GarvinEngine;
using namespace GarvinEngine::Network;

SINGLETON_DEFINE(SessionManager);

SessionManager::~SessionManager()
{
  _clear();
}

void SessionManager::init()
{
  _session_pool.clear();
  _session_map.clear();
  _session_sockfd_map.clear();
  _session_id = 0;
}

Session* SessionManager::create(SOCKET sockfd)
{
  Session* session = NULL;
  if (!_session_pool.empty())
  {
    session = _session_pool.front();
    _session_pool.pop_front();
  }
  else
  {
    session = new Session();
    session->sid(++_session_id);
  }

  session->sockfd(sockfd);

  _session_map[session->sid()] = session;
  _session_sockfd_map[session->sockfd()] = session;
  
  return session;
}

Session* SessionManager::get(uint64 sessionID)
{
  std::map<uint64, Session*>::iterator iter = _session_map.find(sessionID);
  if (iter != _session_map.end()) return iter->second;
  return NULL;
}

Session* SessionManager::get(SOCKET sockfd)
{
  std::map<SOCKET, Session*>::iterator iter = _session_sockfd_map.find(sockfd);
  if (iter != _session_sockfd_map.end()) return iter->second;
  return NULL;
}

void SessionManager::remove(Session* session)
{
  if (session == NULL) return;

  std::map<uint64, Session*>::iterator iter = _session_map.find(session->sid());
  if (iter != _session_map.end()) _session_map.erase(iter);

  std::map<SOCKET, Session*>::iterator iter2 = _session_sockfd_map.find(session->sockfd());
  if (iter2 != _session_sockfd_map.end()) _session_sockfd_map.erase(iter2);
  
  _session_pool.push_back(session);
}

void SessionManager::list(std::vector<Session*>& sessions)
{
  sessions.clear();
  for (std::map<uint64, Session*>::iterator iter = _session_map.begin();
       iter != _session_map.end();
       iter++)
    {
      sessions.push_back(iter->second);
    }
}

void SessionManager::_clear()
{
  Session* session = NULL;
  while(!_session_pool.empty())
  {
    session = _session_pool.front();
    _session_pool.pop_front();
    
    delete session;
    session = NULL;
  }

  for (std::map<uint64, Session*>::iterator iter = _session_map.begin();
       iter != _session_map.end(); iter++)
    {
      delete iter->second;
    }
  _session_map.clear();
  _session_sockfd_map.clear();

}
