
#pragma once

#ifndef _GARVIN_DATA_H_
#define _GARVIN_DATA_H_

#include <public.h>

/**
 * 配置数据类
 * 包括配置数据
 */
namespace GarvinEngine
{
	namespace Config
	{
		class DataGrid
		{
		public:
			DataGrid();
			DataGrid(std::string key, std::string value);
			virtual ~DataGrid();

			std::string getkey();
			std::string getvalue();

			int32 getInt32();
			uint32 getUInt32();

			int64 getInt64();
			uint64 getUInt64();

			float getFloat();
			double getDouble();

		private:
			std::string _key;
			std::string _value;
		};

		class DataRow
		{

		public:
			DataRow();
			virtual ~DataRow();

			std::string getField(uint32 index);

			std::string getString(uint32 index);
			std::string getString(std::string field);

			int32 getInt32(uint32 index);
			int32 getInt32(std::string field);

			uint32 getUInt32(uint32 index);
			uint32 getUInt32(std::string field);

			int64 getInt64(uint32 index);
			int64 getInt64(std::string field);

			uint64 getUInt64(uint32 index);
			uint64 getUInt64(std::string field);

			float getFloat(uint32 index);
			float getFloat(std::string field);

			double getDouble(uint32 index);
			double getDouble(std::string field);

			void add(DataGrid* grid);

			uint32 count();

		private:
			
			bool _checkRange(uint32 index);
			std::string _find(std::string field);

		private:
			std::vector<DataGrid*> _row;
		};

		class DataTable
		{
		public:
			DataTable();
			virtual ~DataTable();

			DataRow* getRow(uint32 index);
			DataRow* getRow(const std::string& key);

			void add(DataRow* row);
			void add(std::string key, DataRow* row);

			uint32 count();

		private:
			std::map<std::string, DataRow*> _table;
			uint32 _idx;
		};
	}
}

#endif