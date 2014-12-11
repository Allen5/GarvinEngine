
#pragma once

#ifndef _CONFIG_FACTORY_H_
#define _CONFIG_FACTORY_H_

#include <public.h>
#include "ConfigLoaderBase.h"


namespace GarvinEngine
{
	namespace Config
	{
		enum EConfigFileType
		{
			CONFIG_FILE_TYPE_INI	= 0x00,	//*.ini格式配置文件
			CONFIG_FILE_TYPE_XML	= 0x01,	//*.xml格式配置文件
			CONFIG_FILE_TYPE_CSV	= 0x02,	//*.csv格式配置文件
			CONFIG_FIEL_TYPE_JSON	= 0x03,	//*.json格式配置文件
			CONFIG_FILE_TYPE_SQL	= 0x04,	//从DB中读取配置文件
			CONFIG_FILE_TYPE_END	= 0xFF,
		};

		class ConfigFactory
		{
			SINGLETON_DECALRE(ConfigFactory);
		public:
			ConfigLoaderBase* create(uint8 type, std::string filename);
		};
	}
}

#endif