
#pragma once

#include <network/client.h>

namespace GarvinEngine
{

	namespace Network
	{

		class TCPClient : public Client
		{
		public:
			virtual bool conn();
			virtual void run();

		private:

			void _init();
			Response* _getReponse();
			Response* _packageDeal(int32 n);

		private:

			int8 _buf[MAX_BUF];
			uint32 _pos;
			
#if defined(_WIN32) || defined(_WIN64)
			int32 _clientfd;
			FD_SET _clientset;
#else
			struct pollfd _clientfd;
#endif
		};
	}

}
