
#include <config/configFactory.h>
#include <config/ConfigLoaders.h>

using namespace GarvinEngine;;
using namespace GarvinEngine::Config;

ConfigLoaderBase* ConfigFactory::create(uint8 type, std::string filename)
{
	switch (type)
	{
	case CONFIG_FILE_TYPE_INI:	return new IniConfigLoader(filename);
	case CONFIG_FILE_TYPE_XML:	return new XMLConfigLoader(filename);
	case CONFIG_FILE_TYPE_CSV:	return new CSVConfigLoader(filename);
	case CONFIG_FIEL_TYPE_JSON: return new JSONConfigLoader(filename);
	case CONFIG_FILE_TYPE_SQL:	return new SQLConfigLoader(filename);
	}
	return NULL;

}
