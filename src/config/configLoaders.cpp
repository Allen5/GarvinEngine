
#include <config/ConfigLoaders.h>

GarvinEngine::Config::IniConfigLoader::IniConfigLoader(std::string filename)
:GarvinEngine::Config::ConfigLoaderBase(filename)
{
}

GarvinEngine::Config::IniConfigLoader::~IniConfigLoader()
{
}

bool GarvinEngine::Config::IniConfigLoader::load()
{
	//todo
	//load config file from Ini
	return false;
}

GarvinEngine::Config::XMLConfigLoader::XMLConfigLoader(std::string filename)
:GarvinEngine::Config::ConfigLoaderBase(filename)
{
}

GarvinEngine::Config::XMLConfigLoader::~XMLConfigLoader()
{
}

bool GarvinEngine::Config::XMLConfigLoader::load()
{
	//todo
	//load config file from XML
	return false;
}

GarvinEngine::Config::CSVConfigLoader::CSVConfigLoader(std::string filename)
:GarvinEngine::Config::ConfigLoaderBase(filename)
{
}

GarvinEngine::Config::CSVConfigLoader::~CSVConfigLoader()
{

}

bool GarvinEngine::Config::CSVConfigLoader::load()
{
	//todo
	//load config file from CSV
	return false;
}

GarvinEngine::Config::JSONConfigLoader::JSONConfigLoader(std::string filename)
:GarvinEngine::Config::ConfigLoaderBase(filename)
{

}

GarvinEngine::Config::JSONConfigLoader::~JSONConfigLoader()
{
}

bool GarvinEngine::Config::JSONConfigLoader::load()
{
	//todo
	//load config file from JSON
	return false;
}


GarvinEngine::Config::SQLConfigLoader::SQLConfigLoader(std::string filename)
:GarvinEngine::Config::ConfigLoaderBase(filename)
{
}

GarvinEngine::Config::SQLConfigLoader::~SQLConfigLoader()
{
}

bool GarvinEngine::Config::SQLConfigLoader::load()
{
	//todo
	//load config file from sql
	return false;
}
