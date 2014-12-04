
#include <config/configData.h>

GarvinEngine::Config::DataGrid::DataGrid()
{
	_key = "";
	_value = "";
}

GarvinEngine::Config::DataGrid::DataGrid(XString key, XString value)
:_key(""),
_value("")
{
}

GarvinEngine::Config::DataGrid::~DataGrid()
{
}

XString GarvinEngine::Config::DataGrid::getkey()
{
	return _key;
}

XString GarvinEngine::Config::DataGrid::getvalue()
{
	return _value;
}

int32 GarvinEngine::Config::DataGrid::getInt32()
{
	return _value.toInt32();
}

uint32 GarvinEngine::Config::DataGrid::getUInt32()
{
	return _value.toUInt32();
}

int64 GarvinEngine::Config::DataGrid::getInt64()
{
	return _value.toInt64();
}

uint64 GarvinEngine::Config::DataGrid::getUInt64()
{
	return _value.toUInt64();
}

float GarvinEngine::Config::DataGrid::getFloat()
{
	return _value.toFloat();
}

double GarvinEngine::Config::DataGrid::getDouble()
{
	return _value.toDouble();
}


GarvinEngine::Config::DataRow::DataRow()
{
	_row.clear();
}

GarvinEngine::Config::DataRow::~DataRow()
{
}

XString GarvinEngine::Config::DataRow::getField(uint32 index)
{
	if (!_checkRange(index)) return 0;
	return _row[index]->getkey();
}

XString GarvinEngine::Config::DataRow::getString(uint32 index)
{
	if (!_checkRange(index)) return 0;
	return _row[index]->getvalue();
}

XString GarvinEngine::Config::DataRow::getString(XString field)
{
	return _find(field);
}

int32 GarvinEngine::Config::DataRow::getInt32(uint32 index)
{
	if (!_checkRange(index)) return 0;
	return _row[index]->getInt32();
}

int32 GarvinEngine::Config::DataRow::getInt32(XString field)
{
	return _find(field).toInt32();
}

uint32 GarvinEngine::Config::DataRow::getUInt32(uint32 index)
{
	if (!_checkRange(index)) return 0;
	return _row[index]->getUInt32();
}

uint32 GarvinEngine::Config::DataRow::getUInt32(XString field)
{
	return _find(field).toUInt32();
}

int64 GarvinEngine::Config::DataRow::getInt64(uint32 index)
{
	if (!_checkRange(index)) return 0;
	return _row[index]->getInt64();
}

int64 GarvinEngine::Config::DataRow::getInt64(XString field)
{
	return _find(field).toInt64();
}

uint64 GarvinEngine::Config::DataRow::getUInt64(uint32 index)
{
	if (!_checkRange(index)) return 0;
	return _row[index]->getUInt64();
}

uint64 GarvinEngine::Config::DataRow::getUInt64(XString field)
{
	return _find(field).toUInt64();
}

float GarvinEngine::Config::DataRow::getFloat(uint32 index)
{
	if (!_checkRange(index)) return 0.0f;
	return _row[index]->getFloat();
}

float GarvinEngine::Config::DataRow::getFloat(XString field)
{
	return _find(field).toFloat();
}

double GarvinEngine::Config::DataRow::getDouble(uint32 index)
{
	if (!_checkRange(index)) return 0.0;
	return _row[index]->getDouble();
}

double GarvinEngine::Config::DataRow::getDouble(XString field)
{
	return _find(field).toDouble();
}

void GarvinEngine::Config::DataRow::add(DataGrid* grid)
{
	_row.push_back(grid);
}

XString GarvinEngine::Config::DataRow::_find(XString field)
{
	std::vector<DataGrid*>::iterator iter = _row.begin();
	for (; iter != _row.begin(); iter++) {
		if ((*iter)->getkey() == field) return (*iter)->getvalue();
	}
	return XString("");
}

bool GarvinEngine::Config::DataRow::_checkRange(uint32 index)
{
	if (index < 0 || index > _row.size()) return false;
	return true;
}

GarvinEngine::Config::DataTable::DataTable()
{
	_table.clear();
}

GarvinEngine::Config::DataTable::~DataTable()
{
}

GarvinEngine::Config::DataRow* GarvinEngine::Config::DataTable::getRow(uint32 index)
{
	if (index < 0 || index > _table.size()) return NULL;
	return _table[index];
}

void GarvinEngine::Config::DataTable::add(DataRow* row)
{
	_table.push_back(row);
}
