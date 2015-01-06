
#include <util/datetime.h>
#include <sstream>

using namespace std;
using namespace GarvinEngine;
using namespace GarvinEngine::Util;

Datetime::Datetime()
: _timestamp(0)
, _year(0)
, _month(0)
, _day(0)
, _hour(0)
, _minute(0)
, _second(0)
{
	timeb t;
	ftime(&t);
	_maketime(t.time);

	//需要放在 maketime 之后。否则会重置 m_timestamp;
	timestamp(1000 * t.time + t.millitm);
}

Datetime::~Datetime()
{
}

std::string Datetime::getDate()
{
	char buf[32] = { 0 };
	sprintf_s(buf, "%04d-%02d-%02d", _year, _month, _day);
	return string(buf);
}

std::string Datetime::getTime()
{
	char buf[32] = { 0 };
	sprintf_s(buf, "%02d:%02d:%02d", _hour, _minute, _second);
	return string(buf);
}

std::string Datetime::getDateTime()
{
	return getDate() + " " + getTime();
}

void Datetime::_maketime(time_t now)
{
	struct tm _now;
	localtime_s(&_now, &now);

	year(1900 + _now.tm_year);	//year from 1900;
	month(_now.tm_mon + 1);		//tm_mon [0, 11].
	day(_now.tm_mday);
	hour(_now.tm_hour);
	minute(_now.tm_min);
	second(_now.tm_sec);
	timestamp(0);
}
