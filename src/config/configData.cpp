
#include <config/configData.h>
#include <util/xstring.h>

using namespace GarvinEngine::Util;

GarvinEngine::Config::DataGrid::DataGrid()
{
	_key = "";
	_value = "";
}

GarvinEngine::Config::DataGrid::DataGrid(std::string key, std::string value)
:_key(key),
_value(value)
{
}

GarvinEngine::Config::DataGrid::~DataGrid()
{
}

std::string GarvinEngine::Config::DataGrid::getkey()
{
	return _key;
}

std::string GarvinEngine::Config::DataGrid::getvalue()
{
	return _value;
}

int32 GarvinEngine::Config::DataGrid::getInt32()
{
	int32 var = 0;
	XString::getInstance()->translate(_value, var);
	return var;
}

uint32 GarvinEngine::Config::DataGrid::getUInt32()
{
	uint32 var = 0;
	XString::getInstance()->translate(_value, var);
	return var;
}

int64 GarvinEngine::Config::DataGrid::getInt64()
{
	int64 var = 0;
	XString::getInstance()->translate(_value, var);
	return var;
}

uint64 GarvinEngine::Config::DataGrid::getUInt64()
{
	uint64 var = 0;
	XString::getInstance()->translate(_value, var);
	return var;
}

float GarvinEngine::Config::DataGrid::getFloat()
{
	float var = 0.0f;
	XString::getInstance()->translate(_value, var);
	return var;
}

double GarvinEngine::Config::DataGrid::getDouble()
{
	double var = 0;
	XString::getInstance()->translate(_value, var);
	return var;
}


GarvinEngine::Config::DataRow::DataRow()
{
	_row.clear();
}

GarvinEngine::Config::DataRow::~DataRow()
{
}

std::string GarvinEngine::Config::DataRow::getField(uint32 index)
{
	if (!_checkRange(index)) return std::string("");
	return _row[index]->getkey();
}

std::string GarvinEngine::Config::DataRow::getString(uint32 index)
{
	if (!_checkRange(index)) return std::string("");
	return _row[index]->getvalue();
}

std::string GarvinEngine::Config::DataRow::getString(std::string field)
{
	return _find(field);
}

int32 GarvinEngine::Config::DataRow::getInt32(uint32 index)
{
	if (!_checkRange(index)) return 0;
	return _row[index]->getInt32();
}

int32 GarvinEngine::Config::DataRow::getInt32(std::string field)
{
	int32 var;
	XString::getInstance()->translate(_find(field), var);
	return var;
}

uint32 GarvinEngine::Config::DataRow::getUInt32(uint32 index)
{
	if (!_checkRange(index)) return 0;
	return _row[index]->getUInt32();
}

uint32 GarvinEngine::Config::DataRow::getUInt32(std::string field)
{
	uint32 var;
	XString::getInstance()->translate(_find(field), var);
	return var;
}

int64 GarvinEngine::Config::DataRow::getInt64(uint32 index)
{
	if (!_checkRange(index)) return 0;
	return _row[index]->getInt64();
}

int64 GarvinEngine::Config::DataRow::getInt64(std::string field)
{
	int64 var;
	XString::getInstance()->translate(_find(field), var);
	return var;
}

uint64 GarvinEngine::Config::DataRow::getUInt64(uint32 index)
{
	if (!_checkRange(index)) return 0;
	return _row[index]->getUInt64();
}

uint64 GarvinEngine::Config::DataRow::getUInt64(std::string field)
{
	uint64 var;
	XString::getInstance()->translate(_find(field), var);
	return var;
}

float GarvinEngine::Config::DataRow::getFloat(uint32 index)
{
	if (!_checkRange(index)) return 0.0f;
	return _row[index]->getFloat();
}

float GarvinEngine::Config::DataRow::getFloat(std::string field)
{
	float var;
	XString::getInstance()->translate(_find(field), var);
	return var;
}

double GarvinEngine::Config::DataRow::getDouble(uint32 index)
{
	if (!_checkRange(index)) return 0.0;
	return _row[index]->getDouble();
}

double GarvinEngine::Config::DataRow::getDouble(std::string field)
{
	double var;
	XString::getInstance()->translate(_find(field), var);
	return var;
}

void GarvinEngine::Config::DataRow::add(DataGrid* grid)
{
	_row.push_back(grid);
}

std::string GarvinEngine::Config::DataRow::_find(std::string field)
{
	std::vector<DataGrid*>::iterator iter = _row.begin();
	for (; iter != _row.end(); iter++) {
		if ((*iter)->getkey() == field) return (*iter)->getvalue();
	}
	return std::string("");
}

bool GarvinEngine::Config::DataRow::_checkRange(uint32 index)
{
	if (index < 0 || index > _row.size()) return false;
	return true;
}

uint32 GarvinEngine::Config::DataRow::count()
{
	return _row.size();
}

GarvinEngine::Config::DataTable::DataTable()
:_idx(0)
{
	_table.clear();
}

GarvinEngine::Config::DataTable::~DataTable()
{
}

GarvinEngine::Config::DataRow* GarvinEngine::Config::DataTable::getRow(uint32 index)
{
	if (index < 0 || index > _table.size()) return NULL;
	
	std::string key = XString::getInstance()->toString(index);
	std::map<std::string, DataRow*>::iterator iter = _table.find(key);
	if (iter == _table.end()) return NULL;
	return _table[key];
}

GarvinEngine::Config::DataRow* GarvinEngine::Config::DataTable::getRow(const std::string& key)
{
	if (key == "") return NULL;

	std::map<std::string, DataRow*>::iterator iter = _table.find(key);
	if (iter == _table.end()) return NULL;
	return _table[key];
}

void GarvinEngine::Config::DataTable::add(DataRow* row)
{
	std::string key = XString::getInstance()->toString(++_idx);
	this->add(key, row);
}

void GarvinEngine::Config::DataTable::add(std::string key, DataRow* row)
{
	_table[key] = row;
}

uint32 GarvinEngine::Config::DataTable::count()
{
	return _table.size();
}
