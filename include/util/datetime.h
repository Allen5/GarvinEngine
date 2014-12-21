
#pragma once

#include <public.h>

//此头文件尚未在linux下测试，windows下可用来获取毫秒数
//暂时只构造当前时间点
#include <sys/timeb.h>
#include <time.h>

namespace GarvinEngine
{

	namespace Util
	{

		class Datetime
		{

		public:

			Datetime();
			virtual ~Datetime();

		public:

			//获取日期字符串，格式为YYYY-MM-dd
			std::string getDate();

			//获取时间字符串，格式为HH:MM:SS
			std::string getTime();

			//获取日期时间字符串，格式为 YYYY-MM-dd HH:MM:SS
			std::string getDateTime();

		private:

			void _maketime(time_t now);

		private:

			MEMBER_VARIBLE(uint64, timestamp);
			MEMBER_VARIBLE(uint16, year);
			MEMBER_VARIBLE(uint16, month);
			MEMBER_VARIBLE(uint16, day);
			MEMBER_VARIBLE(uint16, hour);
			MEMBER_VARIBLE(uint16, minute);
			MEMBER_VARIBLE(uint16, second);

		};

	}

}