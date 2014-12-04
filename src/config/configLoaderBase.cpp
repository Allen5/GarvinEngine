
#include <config/ConfigLoaderBase.h>

GarvinEngine::Config::ConfigLoaderBase::ConfigLoaderBase(std::string filename)
:_filename(filename)
{
}

GarvinEngine::Config::ConfigLoaderBase::~ConfigLoaderBase()
{
}

DataTable* GarvinEngine::Config::ConfigLoaderBase::get()
{
	return table();
}


