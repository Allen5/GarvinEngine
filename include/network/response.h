
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
			Response():_pack(NULL){}
			virtual ~Response() {}

			virtual void unserial(Package* pack){}
			virtual Package* serial() { return NULL; }

		public:
			inline void setProto(uint32 protoID)
			{
				_protoID = protoID;
			}

		protected:

			Package* _pack;

		private:
			MEMBER_VARIBLE(uint32, protoID);

		};

	}

}