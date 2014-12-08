
#pragma once

#ifndef _CONFIG_TYPE_BASE_H_
#define _CONFIG_TYPE_BASE_H_

#include <public.h>
#include <config/configData.h>

using namespace GarvinEngine;
using namespace GarvinEngine::Config;

namespace GarvinEngine
{
	namespace Config
	{
		class ConfigLoaderBase
		{
		public:
			ConfigLoaderBase(std::string filename);
			virtual ~ConfigLoaderBase();

		public:
			virtual bool load() = 0;
			virtual DataTable* get();

		private:
			MEMBER_VARIBLE(std::string, filename);
			MEMBER_VARIBLE(DataTable*, table);
		};
	}
}

#endif