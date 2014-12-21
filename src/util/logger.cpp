
#include <util/logger.h>
#include <util/xstring.h>

using namespace GarvinEngine;
using namespace GarvinEngine::Util;

SINGLETON_DEFINE(Logger);

Logger::~Logger()
{
	_logfile->close();
	delete _logfile;
	_logfile = NULL;
}


void Logger::run()
{
	if (!_create(filename()))  {
		std::cout << "create log file failed(). " << filename() << std::endl;
		return;
	}

	while (true)
	{
		if (!_checkDate() || !_checkSize()) _create(filename());

		if (toConsole()) std::cout << _contents.front() << std::endl;

		_logfile->write(_contents.front().c_str(), _contents.front().length());
		_contents.pop();
		Sleep(100);
	}

}

bool Logger::_create(std::string name)
{	

	_init();

	_curtime = new Datetime();
	_logfilename = _curtime->getDateTime() + "." + XString::getInstance()->toString(_extenID) + "." + name + ".log";

	_logfile = new std::ofstream(_logfilename.c_str(), std::ios::trunc | std::ios::out);
	if (_logfile->is_open()) {
		std::cout << "create file " << _logfilename << " failed" << std::endl;
		return false;
	}

	if (_logfile->fail() || _logfile->bad()) {
		std::cout << "open file " << _logfilename << " failed" << std::endl;
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
}

void Logger::println(const uint8 level, const char* fmt, ...)
{
	Datetime now;
	std::string content = "[" + now.getDateTime() + "][";
	switch (level)
	{
	case LOG_DEBUG: content += "DEBUG"; break;
	case LOG_INFO: content += "INFO"; break;
	case LOG_WARNING: content += "WARNING"; break;
	case LOG_ERROR: content += "ERROR"; break;
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


