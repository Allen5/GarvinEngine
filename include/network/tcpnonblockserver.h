
#pragma once

#include <network/server.h>

namespace GarvinEngine
{

	namespace Network
	{

#define OPEN_MAX 1024

		class TCPNonblockServer : public Server
		{
		public:
			virtual bool open(); 

			virtual Request* request(int32 sockfd);
			virtual void response(SOCKET sockfd, Response* resp);

		private:

			bool _init();
			void _setfd(int32 sockfd);
			bool _bind();
			Session* _accept(sockaddr_in& clientaddr);

			Request* _packgeDeal(int32 n);
				
		private:

			int8 _buf[MAX_BUF];
			uint32 _pos;

			int32 _maxfd;
			int32 _maxindex;

#if defined(_WIN32) || defined(_WIN64)
			int32 _clientfd[OPEN_MAX];
			FD_SET _clientset;
#else
			struct pollfd _clientfd[OPEN_MAX];
#endif
		};

	}

}