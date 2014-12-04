
#ifndef _GARVIN_CONFIGLOADER_H_
#define _GARVIN_CONFIGLOADER_H_

#include <config/ConfigLoaderBase.h>
#include <common/xstring.h>

using namespace GarvinEngine::Common;

namespace GarvinEngine
{

	namespace Config
	{
		class IniConfigLoader : public ConfigLoaderBase
		{
		public:
			IniConfigLoader(XString filename);
			virtual ~IniConfigLoader();

		public:
			bool load();
		};

		class XMLConfigLoader : public ConfigLoaderBase
		{
		public:
			XMLConfigLoader(XString filename);
			virtual ~XMLConfigLoader();

		public: 
			bool load();
		};

		class CSVConfigLoader : public ConfigLoaderBase
		{
		public:
			CSVConfigLoader(XString filename);
			virtual ~CSVConfigLoader();

		public:
			bool load();
		};

		class JSONConfigLoader : public ConfigLoaderBase
		{
		public:
			JSONConfigLoader(XString filename);
			virtual ~JSONConfigLoader();

		public:
			bool load();
		};

		class SQLConfigLoader : public ConfigLoaderBase
		{
		public:
			SQLConfigLoader(XString filename);
			virtual ~SQLConfigLoader();

		public:
			bool load();
		};

	}

}

#endif