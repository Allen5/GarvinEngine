
#ifndef _GARVIN_XSTRING_H_
#define _GARVIN_XSTRING_H_

/**
 * 字符串类，用于封装
 * string, char* 到 int8, uint8, int16, uint16, int32, uint32, int64,uint64,float,double
 * 的转换
 * 以及字符串从utf8 -> gbk, gkb->utf8的转换
 */

#include <public.h>

namespace GarvinEngine
{
	namespace Util
	{
		class XString
		{
		
			SINGLETON_DECALRE(XString);

		public:

			void translate(const std::string& from, int8&	to);
			void translate(const std::string& from, uint8&	to);
			void translate(const std::string& from, int16&	to);
			void translate(const std::string& from, uint16& to);
			void translate(const std::string& from, int32&	to);
			void translate(const std::string& from, uint32& to);
			void translate(const std::string& from, int64&	to);
			void translate(const std::string& from, uint64& to);
			void translate(const std::string& from, float&	to);
			void translate(const std::string& from, double& to);
			void translate(const int8&		from, std::string& to);
			void translate(const uint8&		from, std::string& to);
			void translate(const int16&		from, std::string& to);
			void translate(const uint16&	from, std::string& to);
			void translate(const int32&		from, std::string& to);
			void translate(const uint32&	from, std::string& to);
			void translate(const int64&		from, std::string& to);
			void translate(const uint64&	from, std::string& to);
			void translate(const float&		from, std::string& to);
			void translate(const double&	from, std::string& to);

			//should add toUTF8 interface

			//should add toGBK interface

		private:

			//check whether str is legal
			bool _checkNumber(std::string str);
		};

	}
}
#endif