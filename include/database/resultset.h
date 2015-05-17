
/**
 * 保存sql查询的结果集，并提供 next, get 等接口
 * @Date : 2015.05.07
 * @Author: Allen.Wu
 */

#pragma once

#include <public.h>
#include <mysql.h>

class ResultSet
{

 public:
  ResultSet();
  virtual ~ResultSet();

 public:

  /**
   * 返回下一个result set的指针
   * 用于循环取值
   * @return {true:存在值,false:不存在值}
   */
  bool next();

  int8 getInt8(const char* field);
  uint8 getUInt8(const char* field);

  int16 getInt16(const char* field);
  uint16 getInt16(const char* field);

  int32 getInt32(const char* field);
  uint32 getUInt32(const char* field);

  int64 getInt64(const char* field);
  uint64 getUInt64(const char* field);

  float getFloat(const char* field);
  double getDouble(const char* field);

  std::string getString(const char* field);
  
 private:
  int32 _get_index(const char* key);
  
 private:
  MYSQL_RES* _result_set;
  MYSQL_ROW  _row;
  std::map<std::string, int32> _field_map;
};
