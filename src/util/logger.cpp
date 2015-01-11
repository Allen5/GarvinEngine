
#include <util/logger.h>
#include <util/xstring.h>

using namespace GarvinEngine;
using namespace GarvinEngine::Util;

SINGLETON_DEFINE(Logger);

Logger::~Logger()
{
}


void Logger::run()
{
	if (!_create(_filename))  return;

	while (true)
	{
		if (_contents.size() <= 0) {
			Sleep(10);
			continue;
		}

		if (!_checkDate() || !_checkSize()) _create(_filename);

		if (_toConsole == true) std::cout << _contents.front() << std::endl;

		_logfile->write(_contents.front().c_str(), _contents.front().length());
		_contents.pop();
		Sleep(10);
	}

}

bool Logger::_create(std::string name)
{	

	_init();

	_curtime = new Datetime();

	if (name == "") {//if filename is empty, then set the module name as filename
		std::cout << "Logger::create file error. filename is empty" << std::endl;
		return false;
	}

	if (_logdir != "") { //create dir if dir is not exist
		std::fstream _dir;
		_dir.open(_logdir, std::ios::in);
		if (!_dir) _mkdir(_logdir.c_str());
	}

	_logfilename = _logdir + _curtime->getDate() + "." + XString::getInstance()->toString(_extenID) + "." + name + ".log";

	_logfile = new std::ofstream(_logfilename.c_str(), std::ios::app);
	if (!_logfile) {
		std::cout << GetLastError() << std::endl;
		std::cout << "create file " << _logfilename << " failed" << std::endl;
		return false;
	}

	return true;
}

bool Logger::_checkDate()
{
	if (_curtime == NULL) return false;

	Datetime now;
	if (now.year()	!= _curtime->year())	return false;
	if (now.month() != _curtime->month())	return false;
	if (now.day()	!= _curtime->day())		return false;
	return true;
}

bool Logger::_checkSize()
{
	if (_extenSize == 0) return true;//logfile is not set store limit size

	//check file size;
	std::ifstream in(_logfilename.c_str(), std::ios::in);
	in.seekg(0, std::ios::end);
	uint64 filesize = in.tellg();//return unit is byte
	in.close();

	if (filesize > _extenSize) {
		_extenID++;
		return false;
	}

	return true;
}

void Logger::_init()
{
	if (_logfile) { //if exist, close
		_logfile->close();
		delete _logfile;
		_logfile = NULL;
	}

	if (_curtime) {
		delete _curtime;
		_curtime = NULL;
	}

	_extenID = 0;//reset
	_logfilename = "";

}

void Logger::println(const uint8 level, const char* fmt, ...)
{
	if (level < _out_level) return;

	Datetime now;
	std::string content = "[" + now.getDateTime() + "][";
	switch (level)
	{
	case LOG_LEVEL_DEBUG:	content += "DEBUG"; break;
	case LOG_LEVEL_INFO:	content += "INFO"; break;
	case LOG_LEVEL_WARNING: content += "WARNING"; break;
	case LOG_LEVEL_ERROR:	content += "ERROR"; break;
	}
	content += "]";

	//translate fmt
	va_list args;
	va_start(args, fmt);

	char buf[1024] = { 0 };
	vsnprintf_s(buf, 1024, fmt, args);
	va_end(args);

	content += std::string(buf);
	content += "\n";

	_contents.push(content);
}


void Logger::config(std::string dir, std::string file, bool showConsole /*= true*/, int32 out_level /*=LOG_DEBUG*/, int32 size /*= 0*/)
{
	_logdir = dir;
	_filename = file;
	_extenSize = size;
	_toConsole = showConsole;
	_out_level = out_level;
}

void Logger::_flush()
{
	while (!_contents.empty())
	{
		_logfile->write( _contents.front().c_str(), _contents.front().length());
		_contents.pop();
	}
	_logfile->flush();
	_logfile->close();

	delete _logfile;
	_logfile = NULL;
}

void Logger::flush()
{
	_flush();
	stop();
}


