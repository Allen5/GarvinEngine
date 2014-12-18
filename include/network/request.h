
/**
 * encapulcated request method and info
 */

#pragma once

#include <network/serial.h>

namespace GarvinEngine
{

	namespace Network
	{

		class Request : public ISerial
		{

		public:
			Request() {}
			virtual ~Request() {}
			virtual void unserial(int8* buf) {}
			virtual int8* serial() { return NULL; }

		private:
			MEMBER_VARIBLE(uint32, protoID);
		};

	}

}
