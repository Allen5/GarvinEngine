
#pragma once

#include <public.h>

namespace GarvinEngine
{

	namespace Util
	{
		/**
		 * 此类用于处理 命令行中的参数。根据具体的标记位，得到对应的值
		 * @Date 2014-12-24
		 * @Author: Allen.Wu
		 */
		class ArgsParsor
		{
			SINGLETON_DECALRE(ArgsParsor);
		public:

			/**
			 * 根据参数中的标记，得到对应的值。e.g: -l ../log/。 -l 为标记， ../log/为值.
			 * @param std::string arg, 标记
			 * @param std::string defaultValue. 默认值
			 * @param std::string desc。描述。不做具体用处
			 * @return std::string 得到的值
			 */
			std::string getString(std::string arg, std::string defaultValue = "", std::string desc = ""); 

			/**
			 * 根据参数中的标记，得到对应的值。e.g: -w 2。 -w 为标记， w为值.
			 * @param std::string arg, 标记
			 * @param int32 defaultValue. 默认值
			 * @param std::string desc。描述。不做具体用处
			 * @return int32 得到的值
			 */
			int32 getInt(std::string arg, int32 defaultValue = 0, std::string desc = "");

			/**
			* 根据参数中的标记，得到对应的值。e.g: -c 11.23。 -c 为标记， 11.23为值.
			* @param std::string arg, 标记
			* @param double defaultValue. 默认值
			* @param std::string desc。描述。不做具体用处
			* @return double 得到的值
			*/
			double getDouble(std::string arg, double defaultValue = 0.0, std::string desc = "");

			/**
			 * 根据参数中的标记，得到对应的值。e.g: -c 1。 -c 为标记， 1为值.
			 * @param std::string arg, 标记
			 * @param bool defaultValue. 默认值
			 * @param std::string desc。描述。不做具体用处
			 * @return bool 得到的值
			 */
			bool getBool(std::string arg, bool defaultValue = false, std::string desc = "");

			/**
			 * 获取命令行参数，完成初始化
			 * @param int8** args;
			 * @return void
			 */
			void init(int32 argc, int8** args)
			{
				_argc = argc;
				_args = args;
			}

		private:
			int32  _argc;
			int8** _args;
		};

	}

}