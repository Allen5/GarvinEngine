
/**
 * BaseServer. support the interface but not implement these
 */

#pragma once

#include <public.h>
#include <network/session.h>
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

			virtual bool open() = 0;
			virtual void close();
			virtual bool kick(Session* session);
			virtual void broadcast(std::vector<Session*>& sessions, Response* resp);
			
			void process(Session* session, Request* request);
			void on(uint32 protoId, Handler* handler);

			virtual Request* request(SOCKET sockfd) = 0;
			virtual void response(SOCKET sockfd, Response* resp) = 0;
			
			void addSession(Session* session);
			Session* getSession(uint64 sessionId);
			Session* getSessionBySockfd(int32 sockfd);
			void removeSession(uint64 sessionId);
			void listSession(std::vector<Session*>& sessions);

		private:
			std::map<uint64, Session*> _sessions;
			std::map<uint32, Handler*> _handlers;

			MEMBER_VARIBLE(std::string, host);
			MEMBER_VARIBLE(uint16, port);
			MEMBER_VARIBLE(uint32, backlog);
			MEMBER_VARIBLE(SOCKET, listenfd);
			MEMBER_VARIBLE(uint64, sessionID);

		};
	}
}


