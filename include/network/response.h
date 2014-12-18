
#pragma once

#include <public.h>

namespace GarvinEngine
{

	namespace Network
	{
		class Response : public ISerial
		{
		public:
			Response() { }
			virtual ~Response() {}

			virtual void unserial(int8* buf){}
			virtual int8* serial() { return NULL; }

		private:
			MEMBER_VARIBLE(uint32, protoID);

		};
	}

}