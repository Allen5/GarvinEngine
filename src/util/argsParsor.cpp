
#include <util/argsParsor.h>
#include <util/xstring.h>

using namespace std;
using namespace GarvinEngine;
using namespace GarvinEngine::Util;

SINGLETON_DEFINE(ArgsParsor);

string ArgsParsor::getString(string arg, string defaultValue /*= ""*/, string desc /*= ""*/)
{
	for (int i = 0; i < _argc - 1; i++) {
		if (_args[i] == arg) return string(_args[i+1]);
	}
	return defaultValue;
}

int32 ArgsParsor::getInt(string arg, int32 defaultValue /*= 0*/, string desc /*= ""*/)
{
	string val = getString(arg, "0");
	XString::getInstance()->translate(val, defaultValue);
	return defaultValue;
}

double ArgsParsor::getDouble(string arg, double defaultValue /*= 0.0*/, string desc /*= ""*/)
{
	string val = getString(arg, "0.0");
	XString::getInstance()->translate(arg, defaultValue);
	return defaultValue;
}

bool GarvinEngine::Util::ArgsParsor::getBool(std::string arg, bool defaultValue /*= false*/, std::string desc /*= ""*/)
{
	string val = getString(arg, "0");

	int32 ret = 0;
	XString::getInstance()->translate(val, ret);
	
	if (ret == 0) defaultValue = false;
	else		  defaultValue = true;

	return defaultValue;
	
}
