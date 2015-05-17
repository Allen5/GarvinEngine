
#pragma once

/**
 * build prepared sql to avoid sql injection
 * @author : Allen.Wu (allenlikeu@gmail.com)
 * @Date : 2015.05.17
 */

#include <public.h>
#include <mysql.h>

enum ExecuteType {

  EXECUTE_TYPE_INSERT = 1,
  EXECUTE_TYPE_DELETE = 2,
  EXECUTE_TYPE_UPDATE = 3,
  EXECUTE_TYPE_SELECT = 4,
  
};

class PreparedStatement
{
 public:
  PreparedStatement();
  virtual ~PreparedStatement();

 public:

  /** 
   * init all param
   * @param MYSQL*
   * @param string sql
   */
  bool init(MYSQL* mysql, const std::string& sql);

  /**
   * execute sql statement
   * @param uint64, ref out insertedID or affected rows
   * @param int, value range of enum@ExecuteType.
   * @return bool. {true: success, false: failed}
   */
  bool execute(uint64& insertedID, int executeType);
  
  void set(const int32 index, const int8 value);
  void set(const int32 index, const uint8 value);

  void set(const int32 index, const int16 value);
  void set(const int32 index, const uint16 value);
  
  void set(const int32 index, const int32 value);
  void set(const int32 index, const uint32 value);

  void set(const int32 index, const int64 value);
  void set(const int32 index, const uint64 value);
  
  void set(const int32 index, const float value);
  void set(const int32 index, const double value);

  void set(const int32 index, const std::string& value);
  
 private:

  MYSQL_STMT* _stmt;
  MYSQL_BIND* _bind;
  uint32 _param_cnt;
  
};
