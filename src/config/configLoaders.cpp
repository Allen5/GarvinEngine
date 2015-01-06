
#include <config/ConfigLoaders.h>

#include <util/iniParsor.h>
#include <fstream>

using namespace GarvinEngine::Util;

GarvinEngine::Config::IniConfigLoader::IniConfigLoader(std::string filename)
:GarvinEngine::Config::ConfigLoaderBase(filename)
{
}

GarvinEngine::Config::IniConfigLoader::~IniConfigLoader()
{
}

bool GarvinEngine::Config::IniConfigLoader::load()
{
	std::vector<std::string> vecSection;
	vecSection.clear();

	std::ifstream in;
	in.open(filename().c_str(), std::ios::in);
	
	if (!in) return false; 
	if (in.bad()) { in.close(); return false; }

	IniParsor::getInstance()->listSections(in, vecSection);
	if (vecSection.size() == 0) { in.close(); return false; }

	DataTable* tab = new DataTable();
	std::vector<std::string>::iterator iter = vecSection.begin();
	for (; iter != vecSection.end(); iter++)
	{
		IniParsor::getInstance()->listKV(in, *iter, tab);
	}
	in.close();

	table(tab);
	return true;
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
