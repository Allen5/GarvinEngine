
/**
 * encapulcated request method and info
 */

#pragma once

#include <network/package.h>
#include <network/serial.h>

namespace GarvinEngine
{

	namespace Network
	{

		class Request : public ISerial
		{

		public:
			Request();
			Request(Package* pack);
			virtual ~Request() {}
			virtual void unserial() {}
			virtual Package* serial() { return NULL; }

		private:
			MEMBER_VARIBLE(uint32, protoID);
		};

	}

}
