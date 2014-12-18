
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

		enum ServerType
		{
			//simple server. single thread, single process and handle message with block api
			SERVER_TYPE_SIMPLE = 1,
			//thread server. support thread pool. user could config the pool size
			SERVER_TYPE_THREAD = 2,
			//proccess server. support process pool. user could config the pool size
			SERVER_TYPE_PROCESS = 3,
			//non-block server. handle message in asynchronus way.
			SERVER_TYPE_NON_BLOCK = 4,

			//END
			SERVER_TYPE_END,
		};

		//message protocol type
		//could use multi by and operation
		enum ProtoType
		{
			PROTO_TYPE_TCP = 0x01,
			PROTO_TYPE_UDP = 0x02,
			PROTO_TYPE_HTTP = 0X04,

			//END
			PROTO_TYPE_END,
		};

		class Server
		{
		public:

			Server();
			virtual ~Server();

			virtual bool open() = 0;
			virtual void close();
			virtual bool kick(Session* session);
			virtual void broadcast(std::vector<Session*>& sessions, Response* response);
			
			void process(Session* session, Request* request);
			void on(uint32 protoId, Handler* handler);
			
			void addSession(Session* session);
			Session* getSession(uint64 sessionId);
			void removeSession(uint64 sessionId);
			void listSession(std::vector<Session*>& sessions);

		protected:

			bool _bind();
			Session* _accept(sockaddr_in& clientaddr);

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

