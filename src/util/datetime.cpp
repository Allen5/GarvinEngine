
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
	std::ostringstream out;
	out.fill(0); //不齐补0

	out.width(4); //YYYY显示年
	out << _year;
	out << "-"; //分隔符 
	out.width(2); //MM 显示月
	out << _month;
	out << "-";
	out << _day; //dd 显示天

	return out.str();
}

std::string Datetime::getTime()
{
	std::ostringstream out;
	out.fill(0);

	out.width(2);
	out << _hour;
	out << ":";
	out << _minute;
	out << ":";
	out << _second;

	return out.str();
}

std::string Datetime::getDateTime()
{
	return this->getDate() + " " + this->getTime();
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
