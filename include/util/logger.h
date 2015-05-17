
#pragma once

#include <public.h>
#include <base/thread.h>
#include <util/datetime.h>
#include <fstream>
#if defined(_WIN32) || defined(_WIN64)
#include <direct.h>
#else
#include <sys/stat.h>
#endif


#define LOG_DEBUG(fmt, ...)	do { Logger::getInstance()->println(LOG_LEVEL_DEBUG,	fmt, __VA_ARGS__); } while(0);
#define LOG_INFO(fmt, ...)	do { Logger::getInstance()->println(LOG_LEVEL_INFO,     fmt, __VA_ARGS__); } while(0);
#define LOG_WARN(fmt, ...)	do { Logger::getInstance()->println(LOG_LEVEL_WARNING,	fmt, __VA_ARGS__); } while(0);
#define LOG_ERROR(fmt, ...)	do { Logger::getInstance()->println(LOG_LEVEL_ERROR,	fmt, __VA_ARGS__); } while(0);

enum LogLevel
  {
    LOG_LEVEL_DEBUG		= 1,	
    LOG_LEVEL_INFO		= 2,	
    LOG_LEVEL_WARNING	        = 3,
    LOG_LEVEL_ERROR		= 4,
    LOG_LEVEL_END,
  };

class Logger : public Thread
{
  SINGLETON_DECALRE(Logger);
 public:

  virtual ~Logger();

  virtual void run();
  void println(const uint8 level, const char* fmt = "", ...);

  /**
   * 配置日志文件的路径，日志文件名称，日志文件固定大小
   * @param std::string dir
   * @param std::string file
   * @param bool show log content on console
   * @param int32 log level
   * @param int32 size
   * @return void
   */
  void config(std::string dir, std::string file, bool showConsole = true, int32 out_level = LOG_LEVEL_DEBUG, int32 size = 0);

  /**
   * 将缓冲中的日志信息输出到文件。用于主线程退出时
   * @param void
   * @return void
   */
  void flush();

 private:

  void _init();

  bool _create(std::string name);
  bool _checkDate();
  bool _checkSize();

  void _flush();

 private:
  std::ofstream* _logfile;
  uint32 _extenID;
  std::string _logfilename;
			
  std::string _filename;
  std::string _logdir;
  bool _toConsole;
  int32 _extenSize;

  Datetime* _curtime;
  int32 _out_level;

  std::queue<std::string> _contents;
};
