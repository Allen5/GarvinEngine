
#ifndef _GARVIN_CONFIGLOADER_H_
#define _GARVIN_CONFIGLOADER_H_

#include <config/ConfigLoaderBase.h>

namespace GarvinEngine
{

	namespace Config
	{
		class IniConfigLoader : public ConfigLoaderBase
		{
		public:
			IniConfigLoader(std::string filename);
			virtual ~IniConfigLoader();

		public:
			bool load();
		};

		class XMLConfigLoader : public ConfigLoaderBase
		{
		public:
			XMLConfigLoader(std::string filename);
			virtual ~XMLConfigLoader();

		public: 
			bool load();
		};

		class CSVConfigLoader : public ConfigLoaderBase
		{
		public:
			CSVConfigLoader(std::string filename);
			virtual ~CSVConfigLoader();

		public:
			bool load();
		};

		class JSONConfigLoader : public ConfigLoaderBase
		{
		public:
			JSONConfigLoader(std::string filename);
			virtual ~JSONConfigLoader();

		public:
			bool load();
		};

		class SQLConfigLoader : public ConfigLoaderBase
		{
		public:
			SQLConfigLoader(std::string filename);
			virtual ~SQLConfigLoader();

		public:
			bool load();
		};

	}

}

#endif