
#pragma once

#ifndef _GARVIN_DATA_H_
#define _GARVIN_DATA_H_

#include <public.h>
#include <common/xstring.h>

using namespace GarvinEngine::Common;

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
			DataGrid(XString key, XString value);
			virtual ~DataGrid();

			XString getkey();
			XString getvalue();

			int32 getInt32();
			uint32 getUInt32();

			int64 getInt64();
			uint64 getUInt64();

			float getFloat();
			double getDouble();

		private:
			XString _key;
			XString _value;
		};

		class DataRow
		{

		public:
			DataRow();
			virtual ~DataRow();

			XString getField(uint32 index);

			XString getString(uint32 index);
			XString getString(XString field);

			int32 getInt32(uint32 index);
			int32 getInt32(XString field);

			uint32 getUInt32(uint32 index);
			uint32 getUInt32(XString field);

			int64 getInt64(uint32 index);
			int64 getInt64(XString field);

			uint64 getUInt64(uint32 index);
			uint64 getUInt64(XString field);

			float getFloat(uint32 index);
			float getFloat(XString field);

			double getDouble(uint32 index);
			double getDouble(XString field);

			void add(DataGrid* grid);

		private:
			
			bool _checkRange(uint32 index);
			XString _find(XString field);

		private:
			std::vector<DataGrid*> _row;
		};

		class DataTable
		{
		public:
			DataTable();
			virtual ~DataTable();

			DataRow* getRow(uint32 index);

			void add(DataRow* row);

		private:
			std::vector<DataRow*> _table;
		};
	}
}

#endif