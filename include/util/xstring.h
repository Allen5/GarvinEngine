
#ifndef _GARVIN_XSTRING_H_
#define _GARVIN_XSTRING_H_

/**
 * �ַ����࣬���ڷ�װ
 * string, char* �� int8, uint8, int16, uint16, int32, uint32, int64,uint64,float,double
 * ��ת��
 * �Լ��ַ�����utf8 -> gbk, gkb->utf8��ת��
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

			std::string toString(const int8&		from);
			std::string toString(const uint8&		from);
			std::string toString(const int16&		from);
			std::string toString(const uint16&		from);
			std::string toString(const int32&		from);
			std::string toString(const uint32&		from);
			std::string toString(const int64&		from);
			std::string toString(const uint64&		from);
			std::string toString(const float&		from);
			std::string toString(const double&		from);

			//should add toUTF8 interface

			//should add toGBK interface

		private:

			//check whether str is legal
			bool _checkNumber(std::string str);
		};

	}
}
#endif