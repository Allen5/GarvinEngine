
#pragma once

#ifndef _CONFIG_TYPE_BASE_H_
#define _CONFIG_TYPE_BASE_H_

#include <public.h>
#include <config/configData.h>
#include <common/xstring.h>

using namespace GarvinEngine;
using namespace GarvinEngine::Config;
using namespace GarvinEngine::Common;

namespace GarvinEngine
{
	namespace Config
	{
		class ConfigLoaderBase
		{
		public:
			ConfigLoaderBase(XString filename);
			virtual ~ConfigLoaderBase();

		public:
			virtual bool load() = 0;
			virtual DataTable* get();

		private:
			MEMBER_VARIBLE(XString, filename);
			MEMBER_VARIBLE(DataTable*, table);
		};
	}
}

#endif