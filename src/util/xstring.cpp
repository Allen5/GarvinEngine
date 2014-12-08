
#include <util/xstring.h>

#include <sstream>
#include <regex>

using namespace GarvinEngine::Util;
using namespace std;


bool XString::_checkNumber(std::string str)
{
	if (str == "") return false;
	
	//正则，验证字符串为数字（整数、浮点数）
	string rgx = "^[-]{0,1}\\d+[\\.]{0,1}\\d+$";
	regex exp(rgx);

	return regex_match(str, exp);
}


void GarvinEngine::Util::XString::translate(const std::string& from, int8& to)
{
	if (!_checkNumber(from)) { to = 0; return; }

	stringstream ss;
	ss << from;
	ss >> to;
	ss.clear();
}

void GarvinEngine::Util::XString::translate(const std::string& from, uint8& to)
{
	if (!_checkNumber(from)) { to = 0; return; }

	stringstream ss;
	ss << from;
	ss >> to;
	ss.clear();
}

void GarvinEngine::Util::XString::translate(const std::string& from, int16& to)
{
	if (!_checkNumber(from)) { to = 0; return; }

	stringstream ss;
	ss << from;
	ss >> to;
	ss.clear();
}

void GarvinEngine::Util::XString::translate(const std::string& from, uint16& to)
{
	if (!_checkNumber(from)) { to = 0; return; }

	stringstream ss;
	ss << from;
	ss >> to;
	ss.clear();
}

void GarvinEngine::Util::XString::translate(const std::string& from, int32& to)
{
	if (!_checkNumber(from)) { to = 0; return; }

	stringstream ss;
	ss << from;
	ss >> to;
	ss.clear();
}

void GarvinEngine::Util::XString::translate(const std::string& from, uint32& to)
{
	if (!_checkNumber(from)) { to = 0; return; }

	stringstream ss;
	ss << from;
	ss >> to;
	ss.clear();
}

void GarvinEngine::Util::XString::translate(const std::string& from, int64& to)
{
	if (!_checkNumber(from)) { to = 0; return; }

	stringstream ss;
	ss << from;
	ss >> to;
	ss.clear();
}

void GarvinEngine::Util::XString::translate(const std::string& from, uint64& to)
{
	if (!_checkNumber(from)) { to = 0; return; }

	stringstream ss;
	ss << from;
	ss >> to;
	ss.clear();
}

void GarvinEngine::Util::XString::translate(const std::string& from, float& to)
{
	if (!_checkNumber(from)) { to = 0.0f; return; }

	stringstream ss;
	ss << from;
	ss >> to;
	ss.clear();
}

void GarvinEngine::Util::XString::translate(const std::string& from, double& to)
{
	if (!_checkNumber(from)) { to = 0; return; }

	stringstream ss;
	ss << from;
	ss >> to;
	ss.clear();
}

void GarvinEngine::Util::XString::translate(const int8& from, std::string& to)
{
	stringstream ss;
	ss << from;
	ss >> to;
	ss.clear();
}

void GarvinEngine::Util::XString::translate(const uint8& from, std::string& to)
{
	stringstream ss;
	ss << from;
	ss >> to;
	ss.clear();
}

void GarvinEngine::Util::XString::translate(const int16& from, std::string& to)
{
	stringstream ss;
	ss << from;
	ss >> to;
	ss.clear();
}

void GarvinEngine::Util::XString::translate(const uint16& from, std::string& to)
{
	stringstream ss;
	ss << from;
	ss >> to;
	ss.clear();
}

void GarvinEngine::Util::XString::translate(const int32& from, std::string& to)
{
	stringstream ss;
	ss << from;
	ss >> to;
	ss.clear();
}

void GarvinEngine::Util::XString::translate(const uint32& from, std::string& to)
{
	stringstream ss;
	ss << from;
	ss >> to;
	ss.clear();
}

void GarvinEngine::Util::XString::translate(const int64& from, std::string& to)
{
	stringstream ss;
	ss << from;
	ss >> to;
	ss.clear();
}

void GarvinEngine::Util::XString::translate(const uint64& from, std::string& to)
{
	stringstream ss;
	ss << from;
	ss >> to;
	ss.clear();
}

void GarvinEngine::Util::XString::translate(const float& from, std::string& to)
{
	stringstream ss;
	ss << from;
	ss >> to;
	ss.clear();
}

void GarvinEngine::Util::XString::translate(const double& from, std::string& to)
{
	stringstream ss;
	ss << from;
	ss >> to;
	ss.clear();
}

