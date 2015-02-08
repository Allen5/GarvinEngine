
#pragma once

#include <network/client.h>

namespace GarvinEngine
{

	namespace Network
	{

		class TCPClient : public Client
		{
		public:
			virtual bool conn(std::string serverIP, uint16 serverPort, uint32 innerTime);
			virtual void run();


		private:

			void _init();
			Response* _getResp();

		private:
#if defined(_WIN32) || defined(_WIN64)
			int32 _clientfd;
			FD_SET _clientset;
#else
			struct pollfd _clientfd;
#endif
		};
	}

}