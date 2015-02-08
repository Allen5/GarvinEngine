
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
			 * ���ӷ�����
			 * @param string ������IP
			 * @param uint16 �������˿�
			 * @param uint32 �������ʱ�䣬0��������
			 * @return bool
			 */
			virtual bool conn(std::string serverIP, uint16 serverPort, uint32 innerTime) = 0;

			/**
			 * �ر�����
			 * @return void
			 */
			void close();

			/**
			 * ע��request, response �� handler
			 * @param uint32 Э��
			 * @param Handler* handlerָ��
			 * @return void
			 */
			void onResponse(uint32 proto, Handler* handler);

			/**
			 * ע���������
			 * @param uint32 Э���
			 * @param Handler* handlerָ��
			 * @return void
			 */
			void onNotify(uint32 proto, Handler* handler);

			/**
			 * �������ӹر��¼�
			 * @param Handler* handler ָ��
			 * @return void
			 */
			void onClose(Handler* handler);

			/**
			 * �ַ�request����
			 * @param Request* ������Ϣ��ָ��
			 * @return void
			 */
			void process(Response* resp);

			virtual void run();


		private:
			MEMBER_VARIBLE(std::string, ip);
			MEMBER_VARIBLE(uint16, port);
			MEMBER_VARIBLE(SOCKET, sockfd);
			MEMBER_VARIBLE(uint32, reconnInner); //�������ʱ��,��

			std::map<uint32, Handler*> _handlers;
			Handler* _closeHandler;

		};

	}
}