
/**
 * BaseServer. support the interface but not implement these
 */

#pragma once

#include <network/netcommon.h>
#include <network/sessionManager.h>
#include <network/request.h>
#include <network/response.h>
#include <network/handler.h>

namespace GarvinEngine 
{

	namespace Network
	{

		class Server
		{
		public:

			Server();
			virtual ~Server();

			void config(std::string host = "127.0.0.1", uint16 port = 9090, uint16 backlog = 10);

			virtual bool open() = 0;
			virtual void halt();
			virtual bool kick(Session* session);
			virtual void broadcast(std::vector<Session*>& sessions, Response* resp);
			
			void process(Session* session, Request* request);
			void on(uint32 protoId, Handler* handler);

			virtual Request* request(SOCKET sockfd) = 0;
			virtual void response(SOCKET sockfd, Response* resp) = 0;

			SessionManager* getSessionManager() { return _session_manager; }
		private:

			SessionManager* _session_manager;
			std::map<uint32, Handler*> _handlers;

			MEMBER_VARIBLE(std::string, host);
			MEMBER_VARIBLE(uint16, port);
			MEMBER_VARIBLE(uint32, backlog);
			MEMBER_VARIBLE(SOCKET, listenfd);
			MEMBER_VARIBLE(uint64, sessionID);

		};
	}
}


