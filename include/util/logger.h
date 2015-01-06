
#pragma once

#include <public.h>
#include <util/thread.h>
#include <util/datetime.h>
#include <fstream>
#include <direct.h>

namespace GarvinEngine
{

	namespace Util
	{

#define LOG_DEBUG(fmt, ...)	do { Logger::getInstance()->println(LOG_DEBUG,		fmt, __VA_ARGS__); } while(0);
#define LOG_INFO(fmt, ...)	do { Logger::getInstance()->println(LOG_INFO,		fmt, __VA_ARGS__); } while(0);
#define LOG_WARN(fmt, ...)	do { Logger::getInstance()->println(LOG_WARNING,	fmt, __VA_ARGS__); } while(0);
#define LOG_ERROR(fmt, ...)	do { Logger::getInstance()->println(LOG_ERROR,		fmt, __VA_ARGS__); } while(0);

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

			/**
			 * 配置日志文件的路径，日志文件名称，日志文件固定大小
			 * @param std::string dir
			 * @param std::string file
			 * @param bool show log content on console
			 * @param int32 size
			 * @return void
			 */
			void config(std::string dir, std::string file, bool showConsole = true, int32 size = 0);

		private:

			void _init();

			bool _create(std::string name);
			bool _checkDate();
			bool _checkSize();

		private:
			std::ofstream* _logfile;
			uint32 _extenID;
			std::string _logfilename;
			
			std::string _filename;
			std::string _logdir;
			bool _toConsole;
			int32 _extenSize;

			Datetime* _curtime;

			std::queue<std::string> _contents;
		};

	}

}