
#include <common/xstring.h>


GarvinEngine::Common::XString::XString()
:_str("")
{
}

GarvinEngine::Common::XString::XString(char* str)
:_str(str)
{

}

GarvinEngine::Common::XString::XString(std::string str)
:_str(str)
{
}

GarvinEngine::Common::XString::~XString()
{
}

bool GarvinEngine::Common::XString::operator == (GarvinEngine::Common::XString& const obj)
{
	return _str == obj.str();
}

int8 GarvinEngine::Common::XString::toInt8()
{
	if (!_check()) return 0;
	return static_cast<int8>(toInt32());
}

uint8 GarvinEngine::Common::XString::toUint8()
{
	if (!_check()) return 0;
	return static_cast<uint8>(toUInt32());
}

int16 GarvinEngine::Common::XString::toInt16()
{
	if (!_check()) return 0;
	return static_cast<int16>(toInt32());
}

uint16 GarvinEngine::Common::XString::toUInt16()
{
	if (!_check()) return 0;
	return static_cast<uint16>(toUInt32());
}

int32 GarvinEngine::Common::XString::toInt32()
{
	if (!_check()) return 0;

	//todo

	return 0;
}

uint32 GarvinEngine::Common::XString::toUInt32()
{
	if (!_check()) return 0;
	//todo
	return 0;
}

int64 GarvinEngine::Common::XString::toInt64()
{
	if (!_check()) return 0;
	//todo
	return 0;
}

uint64 GarvinEngine::Common::XString::toUInt64()
{
	if (!_check()) return 0;
	//todo
	return 0;
}

float GarvinEngine::Common::XString::toFloat()
{
	if (!_check()) return 0;
	//todo
	return 0.0f;
}

double GarvinEngine::Common::XString::toDouble()
{
	if (!_check()) return 0;
	//todo
	return 0.0;
}

bool GarvinEngine::Common::XString::_check()
{
	if (_str == "") return false;
	//todo
	//use regular expression to check whether string is legal
	return true;
}
