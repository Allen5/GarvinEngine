
#pragma once

#include <public.h>
#include <network/package.h>

namespace GarvinEngine
{
	namespace Network
	{

		class ISerial
		{
		public:
			ISerial() : _pack(NULL) {};
			virtual ~ISerial() { delete _pack; _pack = NULL; };
			virtual void unserial() = 0;
			virtual Package* serial() = 0;

		protected:
			Package* _pack;
		};

	}

}