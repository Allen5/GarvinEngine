
#pragma once

#include <public.h>

namespace GarvinEngine
{
	namespace Network
	{

		class ISerial
		{
		public:
			ISerial() {};
			virtual ~ISerial() {};
			virtual void unserial(int8* buf) = 0;
			virtual int8* serial() = 0;
		};

	}

}