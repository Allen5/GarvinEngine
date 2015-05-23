
#include <util/xstring.h>
#include <database/resultset.h>

using namespace std;

ResultSet::ResultSet(MYSQL_RES* result)
  :_row(NULL)
{
  _field_map.clear();
  if ( !_init(result) ) {
    //TODO(allenlike@gmail.com):增加日志记录
  }
}

ResultSet::~ResultSet()
{
  if (_result_set) {
    mysql_free_result(_result_set);
    _result_set = NULL;
  }
  _field_map.clear();
}

bool ResultSet::next()
{
  if (_result_set == NULL) return false;
  
  _row = mysql_fetch_row(_result_set);
  if ( !_row ) return false;

  return true;
}

int8 ResultSet::getInt8(const char* field)
{
  int8 ret = 0;
  if (field == NULL) return ret;

  XString::getInstance()->translate(getString(field), ret);
  return 0;
}

uint8 ResultSet::getUInt8(const char* field)
{
  uint8 ret = 0;
  if (field == NULL) return ret;

  XString::getInstance()->translate(getString(field), ret);
  return ret;
}

int16 ResultSet::getInt16(const char* field)
{
  int16 ret = 0;
  if (field == NULL) return ret;

  XString::getInstance()->translate(getString(field), ret);
  return ret;
}

uint16 ResultSet::getUInt16(const char* field)
{
  uint16 ret = 0;
  if (field == NULL) return ret;

  XString::getInstance()->translate(getString(field), ret);
  return ret;
}

int32 ResultSet::getInt32(const char* field)
{
  int32 ret = 0;
  if (field == NULL) return ret;

  XString::getInstance()->translate(getString(field), ret);
  return ret;
}

uint32 ResultSet::getUInt32(const char* field)
{
  uint32 ret = 0;
  if (field == NULL) return ret;

  XString::getInstance()->translate(getString(field), ret);
  return ret;
}

int64 ResultSet::getInt64(const char* field)
{
  int64 ret = 0;
  if (field == NULL) return ret;

  XString::getInstance()->translate(getString(field), ret);
  return ret;
}

uint64 ResultSet::getUInt64(const char* field)
{
  uint64 ret = 0;
  if (field == NULL) return ret;

  XString::getInstance()->translate(getString(field), ret);
  return ret;
}

float ResultSet::getFloat(const char* field)
{
  float ret = 0.0f;
  if (field == NULL) return ret;

  XString::getInstance()->translate(getString(field), ret);
  return ret;
}

double ResultSet::getDouble(const char* field)
{
  double ret = 0.0;
  if (field == NULL) return ret;

  XString::getInstance()->translate(getString(field), ret);
  return ret;
}

std::string ResultSet::getString(const char* field)
{
  string ret = "";
  
  if (field == NULL) return "";

  int32 index = _get_index(field);
  if (index == INVALID) return "";

  return string(_row[index], strlen(_row[index]));
}

bool ResultSet::_init(MYSQL_RES* result)
{
  _result_set = result;

  if (_result_set == NULL) return false;

  uint32 number = mysql_num_fields(_result_set);
  MYSQL_FIELD* fields = mysql_fetch_fields(_result_set);

  for (uint32 i=0; i<number; i++) {
    _field_map[fields[i].name] = i;
  }

  return true;
}

int32 ResultSet::_get_index(const char* key)
{
  int32 ret = INVALID;

  if (key == NULL) return ret;
  
  std::map<std::string, int32>::iterator iter = _field_map.find(key);
  if ( iter != _field_map.end() ) {
    ret = iter->second;
  }

  return ret;
}

