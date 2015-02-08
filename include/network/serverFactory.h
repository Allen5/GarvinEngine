
#pragma once

#include <public.h>
#include <network/server.h>

namespace GarvinEngine
{

	namespace Network
	{

		class ServerFactory
		{
			SINGLETON_DECALRE(ServerFactory);
		public:
			Server* create(int32 serverType, int32 protoType);
		};

	}

}
