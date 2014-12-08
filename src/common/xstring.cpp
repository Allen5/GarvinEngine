
#include <util/xstring>

#include <sstream>
#include <regex>

using namespace GarvinEngine::Util;
using namespace std;

XString::~XString()
{
}

int8 XString::toInt8(std::string str)
{
	if (!_checkNumber(str)) return 0;
	
	int8 var = 0;
	stringstream ss;
	ss << str;
	ss >> var;
	ss.clear();

	return var;
}

uint8 XString::toUint8(std::string str)
{
	if (!_checkNumber(str)) return 0;
	
	uint8 var = 0;
	stringstream ss;
	ss << str;
	ss >> var;
	ss.clear();

	return var;
}

int16 XString::toInt16(std::string str)
{
	if (!_checkNumber(str)) return 0;

	int16 var = 0;
	stringstream ss;
	ss << str;
	ss >> var;
	ss.clear();

	return var;
}

uint16 XString::toUInt16(std::string str)
{
	if (!_checkNumber(str)) return 0;
	
	uint16 var = 0;
	stringstream ss;
	ss << str;
	ss >> var;
	ss.clear();

	return var;
}

int32 XString::toInt32(std::string str)
{
	if (!_checkNumber(str)) return 0;

	int32 var = 0;
	stringstream ss;
	ss << str;
	ss >> var;
	ss.clear();

	return var;
}

uint32 XString::toUInt32(std::string str)
{
	if (!_checkNumber(str)) return 0;
	
	uint32 var = 0;
	stringstream ss;
	ss << str;
	ss >> var;
	ss.clear();
	
	return var;
}

int64 XString::toInt64(std::string str)
{
	if (!_checkNumber(str)) return 0;
	
	int64 var = 0;
	stringstream ss;
	ss << str;
	ss >> var;
	ss.clear();

	return var;
}

uint64 XString::toUInt64(std::string str)
{
	if (!_checkNumber(str)) return 0;
	
	uint64 var = 0;
	stringstream ss;
	ss << str;
	ss >> var;
	ss.clear();
	
	return var;
}

float XString::toFloat(std::string str)
{
	if (!_checkNumber(str)) return 0.0f;
	
	float var = 0;
	stringstream ss;
	ss << str;
	ss >> var;
	ss.clear();

	return var;
}

double XString::toDouble(std::string str)
{
	if (!_checkNumber(str)) return 0.0;
	
	double var = 0;
	stringstream ss;
	ss << str;
	ss >> var;
	ss.clear();

	return var;
}

bool XString::_checkNumber(std::string str)
{
	if (str == "") return false;
	
	//正则，验证字符串为数字（整数、浮点数）
	string rgx = "^[-]{0,1}\\d+[\\.]{0,1}\\d+$";
	regex exp(rgx);

	return regex_match(str, exp);
}

