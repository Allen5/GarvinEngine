
#pragma once

#include <public.h>
#include <util/thread.h>
#include <util/datetime.h>
#include <fstream>

namespace GarvinEngine
{

	namespace Util
	{

#define LOG_DEBUG(fmt, ...)	do { Logger::getInstance()->println(LOG_DEBUG,		fmt, __VA_ARGS__) } while(0);
#define LOG_INFO(fmt, ...)	do { Logger::getInstance()->println(LOG_INFO,		fmt, __VA_ARGS__) } while(0);
#define LOG_WARN(fmt, ...)	do { Logger::getInstance()->println(LOG_WARNING,	fmt, __VA_ARGS__) } while(0);
#define LOG_ERROR(fmt, ...)	do { Logger::getInstance()->println(LOG_ERROR,		fmt, __VA_ARGS__) } while(0);

		enum LogLevel
		{
			LOG_DEBUG		= 1,	
			LOG_INFO		= 2,	
			LOG_WARNING		= 3,
			LOG_ERROR		= 4,
			LOG_LEVEL_END,
		};

		class Logger : public Thread
		{
			SINGLETON_DECALRE(Logger);
		public:

			virtual ~Logger();

			virtual void run();
			void println(const uint8 level, const char* fmt, ...);

		private:

			void _init();

			bool _create(std::string name);
			bool _checkDate();
			bool _checkSize();

		private:
			std::ofstream* _logfile;
			uint32 _extenID;
			std::string _logfilename;

			MEMBER_VARIBLE(bool, toConsole);
			MEMBER_VARIBLE(std::string, filename);
			MEMBER_VARIBLE(uint32, extenSize); //日志固定存储大小
			MEMBER_VARIBLE(Datetime*, curtime);

			std::queue<std::string> _contents;
		};

	}

}