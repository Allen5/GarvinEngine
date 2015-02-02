
#pragma once

#include <public.h>

#if defined(_WIN32) || defined(_WIN64)

#else

#include <sys/time.h>
#include <sys/socket.h>
#include <poll.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <limits.h>

#ifndef INFTIM
#define INFTIM -1
#endif

#endif

namespace GarvinEngine
{

	namespace Network
	{

		static const int32 RET_SUCCESS = 0;
		static const int32 RET_FAILED = -1;

		enum ServerType
		{
			//thread server. support thread pool. user could config the pool size
			SERVER_TYPE_THREAD = 1,
			//proccess server. support process pool. user could config the pool size
			SERVER_TYPE_PROCESS = 2,
			//non-block server. handle message in asynchronus way.
			SERVER_TYPE_NON_BLOCK = 3,

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

		enum SysProtocol
		{//系统协议 0x00000001 ~ 0x00000100
			SYS_PROTO_HEARBEAT = 0x00000001,	//心跳包协议
			SYS_PROTO_END,
		};

	}

}
