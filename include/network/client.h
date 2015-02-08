
#pragma once

#include <public.h>
#include <network/netcommon.h>
#include <network/handler.h>
#include <network/session.h>
#include <util/thread.h>
#include <network/request.h>

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
			/**
			 * 连接服务器
			 * @param string 服务器IP
			 * @param uint16 服务器端口
			 * @param uint32 重连间隔时间，0：不重连
			 * @return bool
			 */
			virtual bool conn(std::string serverIP, uint16 serverPort, uint32 innerTime) = 0;

			/**
			 * 关闭连接
			 * @return void
			 */
			void close();

			/**
			 * 注册request, response 的 handler
			 * @param uint32 协议
			 * @param Handler* handler指针
			 * @return void
			 */
			void onResponse(uint32 proto, Handler* handler);

			/**
			 * 注册监听函数
			 * @param uint32 协议号
			 * @param Handler* handler指针
			 * @return void
			 */
			void onNotify(uint32 proto, Handler* handler);

			/**
			 * 处理连接关闭事件
			 * @param Handler* handler 指针
			 * @return void
			 */
			void onClose(Handler* handler);

			/**
			 * 分发request函数
			 * @param Request* 请求消息的指针
			 * @return void
			 */
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