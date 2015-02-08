
/**
 * marked the connectors address,ip and generate the UUID for session id
 */

#pragma once

#include <network/netcommon.h>
#include <network/request.h>
#include <network/response.h>

//should think about session pool

namespace GarvinEngine
{

	namespace Network 
	{
		class Session
		{
		public:
			Session();
			virtual ~Session();
			bool halt();

		private:

			MEMBER_VARIBLE(uint64, sid);
			MEMBER_VARIBLE(std::string, ip);
			MEMBER_VARIBLE(uint16, port);
			MEMBER_VARIBLE(uint64, loginTime);
			MEMBER_VARIBLE(SOCKET, sockfd);

		};
	}

}

