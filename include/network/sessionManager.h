
#pragma once

#include <public.h>
#include <session.h>

namespace GarvinEngine
{

  namespace Network
  {
    class SessionManager
    {
      SINGLETON_DECALRE(SessionManager);

    public:

      /**
       * desctructor
       */
      virtual ~SessionManager();
      
      /**
       * init session manager
       * @param null
       * @return void
       */
      void init();
      
      /**
       * create session from dead session queue
       * @param uint32 socket file descriptor
       * @return Session*
       */
      Session* create(SOCKET sockfd);

      /**
       * get session by session id
       * @param uint64 session id
       * @return Session*
       */
      Session* get(uint64 sessionID);

      /**
       * get session by socket file descriptor
       * @param SOCKET sockfd
       * @return Session*
       */
      Session* get(SOCKET sockfd);

      /**
       * remove session. and put it to dead session queue
       * @param Session*
       * @return void
       */
      void remove(Session* session);

      /**
       * list session.
       * @param std::vector<Session*>
       * @return void
       */
      void list(std::vector<Session*>& sessions);

    private:

      /**
       * clear session. and delete pointer
       *@param null
       *@return void
       */
      void _clear();

    private:

      std::queue<Session*> _session_pool;
      std::map<uint64, Session*> _session_map;
      std::map<SOCKET, Session*> _session_sockfd_map;

      uint64 _session_id;
    };
  }
}

