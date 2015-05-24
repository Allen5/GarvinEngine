
#include <util/xstring.h>

#include <regex>
#include <cstdlib> //use c++11x attribute stoi,stol,stoul,stoll,stoull,stof,stod

using namespace std;

SINGLETON_DEFINE(XString);

bool XString::_checkNumber(std::string str)
{
	if (str == "") return false;
	
	//正则，验证字符串为数字（整数、浮点数）
	string rgx = "^[-]{0,1}\\d+[\\.]{0,1}\\d*$";
	regex exp(rgx);

	return regex_match(str, exp);
}


void XString::translate(const std::string& from, int8& to)
{
	if (!_checkNumber(from)) { to = 0; return; }
	to = stoi(from);
}

void XString::translate(const std::string& from, uint8& to)
{
	if (!_checkNumber(from)) { to = 0; return; }
	to = stoi(from);
}

void XString::translate(const std::string& from, int16& to)
{
	if (!_checkNumber(from)) { to = 0; return; }
	to = stoi(from);
}

void XString::translate(const std::string& from, uint16& to)
{
	if (!_checkNumber(from)) { to = 0; return; }
	to = stoi(from);
}

void XString::translate(const std::string& from, int32& to)
{
	if (!_checkNumber(from)) { to = 0; return; }
	to = stol(from);
}

void XString::translate(const std::string& from, uint32& to)
{
	if (!_checkNumber(from)) { to = 0; return; }
	to = stoul(from);
}

void XString::translate(const std::string& from, int64& to)
{
	if (!_checkNumber(from)) { to = 0; return; }
	to = stoll(from);
}

void XString::translate(const std::string& from, uint64& to)
{
	if (!_checkNumber(from)) { to = 0; return; }
	to = stoull(from);
}

void XString::translate(const std::string& from, float& to)
{
	if (!_checkNumber(from)) { to = 0.0f; return; }
	to = stof(from);
}

void XString::translate(const std::string& from, double& to)
{
	if (!_checkNumber(from)) { to = 0; return; }
	to = stod(from);
}

std::string XString::toString(const int8& from)
{
  char buf[128] = {0};
  snprintf(buf, 128, "%d", from);
  string ret(buf, strlen(buf));
  return ret;
}

std::string XString::toString(const uint8& from)
{
  char buf[128] = {0};
  snprintf(buf, 128, "%u", from);
  string ret(buf, strlen(buf));
  return ret;
}

std::string XString::toString(const int16& from)
{
  char buf[128] = {0};
  snprintf(buf, 128, "%d", from);
  string ret(buf, strlen(buf));
  return ret;
}

std::string XString::toString(const uint16& from)
{
  char buf[128] = {0};
  snprintf(buf, 128, "%u", from);
  string ret(buf, strlen(buf));
  return ret;
}

std::string XString::toString(const int32& from)
{
  char buf[128] = {0};
  snprintf(buf, 128, "%ld", from);
  string ret(buf, strlen(buf));
  return ret;
}

std::string XString::toString(const uint32& from)
{
  char buf[128] = {0};
  snprintf(buf, 128, "%lu", from);
  string ret(buf, strlen(buf));
  return ret;
}

std::string XString::toString(const int64& from)
{
  char buf[128] = {0};
  snprintf(buf, 128, "%lld", from);
  string ret(buf, strlen(buf));
  return ret;
}

std::string XString::toString(const uint64& from)
{
  char buf[128] = {0};
  snprintf(buf, 128, "%llu", from);
  string ret(buf, strlen(buf));
  return ret;
}

std::string XString::toString(const float& from)
{
  char buf[128] = {0};
  snprintf(buf, 128, "%f", from);
  string ret(buf, strlen(buf));
  return ret;
}

std::string XString::toString(const double& from)
{
  char buf[128] = {0};
  snprintf(buf, 128, "%lf", from);
  string ret(buf, strlen(buf));
  return ret;
}

