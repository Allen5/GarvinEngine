
#ifndef _GARVIN_INIFILEREADER_H_
#define _GARVIN_INIFILEREADER_H_

#include <public.h>
#include <fstream>
#include <config/configData.h>

using namespace GarvinEngine::Config;

namespace GarvinEngine
{
	namespace Util
	{
		class IniFileReader
		{
			SINGLETON(IniFileReader);
		public:
			void listSections(std::ifstream& in,std::vector<std::string> & vecSection);
			void listKV(std::ifstream& in, const std::string& section, DataTable* table);
		};
	}
}

#endif