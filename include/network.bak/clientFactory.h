
#pragma once

#include <public.h>
#include <network/client.h>

namespace GarvinEngine
{

	namespace Network
	{

		class ClientFactory
		{
			SINGLETON_DECALRE(ClientFactory);
		public:
			Client* create(uint32 proto);
		};

	}

}