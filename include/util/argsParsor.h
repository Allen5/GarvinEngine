
#pragma once

#include <public.h>

namespace GarvinEngine
{

	namespace Util
	{
		/**
		 * �������ڴ��� �������еĲ��������ݾ���ı��λ���õ���Ӧ��ֵ
		 * @Date 2014-12-24
		 * @Author: Allen.Wu
		 */
		class ArgsParsor
		{
			SINGLETON_DECALRE(ArgsParsor);
		public:

			/**
			 * ���ݲ����еı�ǣ��õ���Ӧ��ֵ��e.g: -l ../log/�� -l Ϊ��ǣ� ../log/Ϊֵ.
			 * @param std::string arg, ���
			 * @param std::string defaultValue. Ĭ��ֵ
			 * @param std::string desc�����������������ô�
			 * @return std::string �õ���ֵ
			 */
			std::string getString(std::string arg, std::string defaultValue = "", std::string desc = ""); 

			/**
			 * ���ݲ����еı�ǣ��õ���Ӧ��ֵ��e.g: -w 2�� -w Ϊ��ǣ� wΪֵ.
			 * @param std::string arg, ���
			 * @param int32 defaultValue. Ĭ��ֵ
			 * @param std::string desc�����������������ô�
			 * @return int32 �õ���ֵ
			 */
			int32 getInt(std::string arg, int32 defaultValue = 0, std::string desc = "");

			/**
			* ���ݲ����еı�ǣ��õ���Ӧ��ֵ��e.g: -c 11.23�� -c Ϊ��ǣ� 11.23Ϊֵ.
			* @param std::string arg, ���
			* @param double defaultValue. Ĭ��ֵ
			* @param std::string desc�����������������ô�
			* @return double �õ���ֵ
			*/
			double getDouble(std::string arg, double defaultValue = 0.0, std::string desc = "");

			/**
			 * ���ݲ����еı�ǣ��õ���Ӧ��ֵ��e.g: -c 1�� -c Ϊ��ǣ� 1Ϊֵ.
			 * @param std::string arg, ���
			 * @param bool defaultValue. Ĭ��ֵ
			 * @param std::string desc�����������������ô�
			 * @return bool �õ���ֵ
			 */
			bool getBool(std::string arg, bool defaultValue = false, std::string desc = "");

			/**
			 * ��ȡ�����в�������ɳ�ʼ��
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