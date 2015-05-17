
#pragma once

#include <public.h>
#include <network/package.h>

namespace GarvinEngine
{

	namespace Network
	{
		class Response : public ISerial
		{
		public:
			Response(){}
			Response(Package* pack) { if (pack) _pack = pack; }
			virtual ~Response() {}

			virtual void unserial() {}
			virtual Package* serial() { return NULL; }

		public:
			inline void setProto(uint32 protoID)
			{
				_protoID = protoID;
			}

		private:
			MEMBER_VARIBLE(uint32, protoID);

		};

	}

}