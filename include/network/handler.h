
#pragma once

#include <public.h>
#include <network/request.h>
#include <network/response.h>

namespace GarvinEngine
{

	namespace Network
	{
		class Handler
		{
		public:
			Handler();
			virtual ~Handler();
			virtual Response* handle(Request* req);
		};
	}

}