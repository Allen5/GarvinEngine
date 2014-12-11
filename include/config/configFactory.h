
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
			CONFIG_FILE_TYPE_INI	= 0x00,	//*.ini��ʽ�����ļ�
			CONFIG_FILE_TYPE_XML	= 0x01,	//*.xml��ʽ�����ļ�
			CONFIG_FILE_TYPE_CSV	= 0x02,	//*.csv��ʽ�����ļ�
			CONFIG_FIEL_TYPE_JSON	= 0x03,	//*.json��ʽ�����ļ�
			CONFIG_FILE_TYPE_SQL	= 0x04,	//��DB�ж�ȡ�����ļ�
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