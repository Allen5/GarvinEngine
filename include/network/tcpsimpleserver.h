
#pragma once

#include <public.h>
#include <network/server.h>

namespace GarvinEngine
{

	namespace Network
	{

		class TCPSimpleServer : public Server
		{
			virtual bool open();
		};

	}

}