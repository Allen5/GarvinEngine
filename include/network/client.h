
#pragma once

#include <network/netcommon.h>
#include <network/handler.h>
#include <util/thread.h>
#include <network/response.h>

using namespace GarvinEngine::Util;

namespace GarvinEngine
{
	namespace Network
	{

		class Client : public Thread
		{
		public:
			Client();
			virtual ~Client();

		public:

			virtual bool conn() = 0;
			void disconn();

			void onResponse(uint32 proto, Handler* handler);
			void onNotify(uint32 proto, Handler* handler);
			void onClose(Handler* handler);
			void process(Response* resp);

			virtual void run();

		private:
			MEMBER_VARIBLE(std::string, ip);
			MEMBER_VARIBLE(uint16, port);
			MEMBER_VARIBLE(SOCKET, sockfd);
			MEMBER_VARIBLE(uint32, reconnInner); //重连间隔时间,秒

			std::map<uint32, Handler*> _handlers;
			Handler* _closeHandler;

		};

	}
}
