
#ifndef _GARVIN_XSTRING_H_
#define _GARVIN_XSTRING_H_

/**
 * 字符串类，用于封装
 * string, char* 到 int8, uint8, int16, uint16, int32, uint32, int64,uint64,float,double
 * 的转换
 */

#include <public.h>

namespace GarvinEngine
{
	namespace Common
	{
		class XString
		{
		public:
			XString();
			XString(char* str);
			XString(std::string str);
			virtual ~XString();

		public:
			bool operator == (XString& const str2);

		public:

			int8 toInt8();
			uint8 toUint8();
			int16 toInt16();
			uint16 toUInt16();
			int32 toInt32();
			uint32 toUInt32();
			int64 toInt64();
			uint64 toUInt64();
			float toFloat();
			double toDouble();

		private:

			//check whether str is legal
			bool _check();

		private:
			MEMBER_VARIBLE(std::string, str);
		};

	}
}
#endif