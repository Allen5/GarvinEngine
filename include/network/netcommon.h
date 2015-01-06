
#pragma once

namespace GarvinEngine
{

	namespace Network
	{

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