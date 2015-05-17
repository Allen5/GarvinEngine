
#include <database/preparedstatement.h>

using namespace std;

PreparedStatement::PreparedStatement()
  :_stmt(NULL)
  ,_bind(NULL)
  ,_param_cnt(0)
{
}

PreparedStatement::~PreparedStatement()
{
  if ( _stmt ) {
    mysql_stmt_close(_stmt);
    _stmt = NULL;
  }

  if ( _bind ) {
    delete [] _bind;
    _bind = NULL;
  }
}

bool PreparedStatement::init(MYSQL* mysql, const std::string& sql)
{
  mysql_ping(mysql);

  _stmt = mysql_stmt_init(mysql);
  if ( !_stmt ) {
    std::cout << "PreparedStatement::init. mysql_stmt_init failde." << std::endl;
    return false;
  }

  if (mysql_stmt_prepare(_stmt, sql.c_str(), sql.size())) {
    std::cout << "PreparedStatement::init. mysql_stmt_prepare failed. err: " << mysql_stmt_error(_stmt) << std::endl;
    return false;
  }

  _param_cnt = mysql_stmt_param_count(_stmt);
  if ( _param_cnt > 0 ) {

    _bind = new MYSQL_BIND [_param_cnt];
    if ( !_bind ) {
      std::cout << "PreparedStatement::init. new MYSQL_BIND. failed." << std::endl;
      return false;
    }

    memset(_bind, 0, sizeof(MYSQL_BIND) * _param_cnt);
    
  }

  return true;
    
}

bool PreparedStatement::execute(uint64& insertedID, int executeType)
{
  if ( !_stmt ) {
    std::cout << "PreparedStatement::execute(). failed. _stmt is null" << std::endl;
    return false;
  }

  if ( mysql_stmt_bind_param(_stmt, _bind) ) {
    std::cout << "PreparedStatement::execute(). failed. err : " << mysql_stmt_error(_stmt) << std::endl;
    return false;
  }

  if ( mysql_stmt_execute(_stmt) ) {
    std::cout << "PreparedStatement::execute(). failed. err: " << mysql_stmt_error(_stmt) << std::endl;
  }

  if ( executeType == EXECUTE_TYPE_INSERT ) {
    insertedID = mysql_stmt_insert_id(_stmt);
    return true;
  }

  if ( executeType == EXECUTE_TYPE_DELETE
     ||executeType == EXECUTE_TYPE_UPDATE) {
    insertedID = mysql_stmt_affected_rows(_stmt);
    return true;
  }
  
  return true;
}

void PreparedStatement::set(const int32 index, const int8 value)
{
  if ( index >= _param_cnt ) {
    std::cout << "PreparedStatement::set. index too large:" << index << std::endl;
    return ;
  }

  _bind[index].buffer_type = MYSQL_TYPE_TINY;
  _bind[index].buffer = &value;
  _bind[index].is_unsigned = false;
}

void PreparedStatement::set(const int32 index, const uint8 value)
{
  if ( index >= _param_cnt ) {
    std::cout << "PreparedStatement::set. index too large:" << index << std::endl;
    return ;
  }

  _bind[index].buffer_type = MYSQL_TYPE_TINY;
  _bind[index].buffer = &value;
  _bind[index].is_unsigned = true;

}

void PreparedStatement::set(const int32 index, const int16 value)
{
  if ( index >= _param_cnt ) {
    std::cout << "PreparedStatement::set. index too large:" << index << std::endl;
    return ;
  }

  _bind[index].buffer_type = MYSQL_TYPE_SHORT;
  _bind[index].buffer = &value;
  _bind[index].is_unsigned = false;

}

void PreparedStatement::set(cosnt int32 index, const uint16 value)
{
  if ( index >= _param_cnt ) {
    std::cout << "PreparedStatement::set. index too large:" << index << std::endl;
    return ;
  }

  _bind[index].buffer_type = MYSQL_TYPE_SHORT;
  _bind[index].buffer = &value;
  _bind[index].is_unsigned = true;

}

void PreparedStatement::set(const int32 index, const int32 value)
{
  if ( index >= _param_cnt ) {
    std::cout << "PreparedStatement::set. index too large:" << index << std::endl;
    return ;
  }

  _bind[index].buffer_type = MYSQL_TYPE_LONG;
  _bind[index].buffer = &value;
  _bind[index].is_unsigned = false;

}

void PreparedStatement::set(const int32 index, const uint32 value)
{
  if ( index >= _param_cnt ) {
    std::cout << "PreparedStatement::set. index too large:" << index << std::endl;
    return ;
  }

  _bind[index].buffer_type = MYSQL_TYPE_LONG;
  _bind[index].buffer = &value;
  _bind[index].is_unsigned = true;

}

void PreparedStatement::set(const int32 index, const int64 value)
{
  if ( index >= _param_cnt ) {
    std::cout << "PreparedStatement::set. index too large:" << index << std::endl;
    return ;
  }

  _bind[index].buffer_type = MYSQL_TYPE_LONGLONG;
  _bind[index].buffer = &value;
  _bind[index].is_unsigned = false;

}

void PreparedStatement::set(const int32 index, const uint64 value)
{
  if ( index >= _param_cnt ) {
    std::cout << "PreparedStatement::set. index too large:" << index << std::endl;
    return ;
  }

  _bind[index].buffer_type = MYSQL_TYPE_LONGLONG;
  _bind[index].buffer = &value;
  _bind[index].is_unsigned = true;

}

void PreparedStatement::set(const int32 index, const float value)
{
  if ( index >= _param_cnt ) {
    std::cout << "PreparedStatement::set. index too large:" << index << std::endl;
    return ;
  }

  _bind[index].buffer_type = MYSQL_TYPE_FLOAT;
  _bind[index].buffer = &value;
  _bind[index].is_unsigned = false;

}

void PreparedStatement::set(const int32 index, const double value)
{
  if ( index >= _param_cnt ) {
    std::cout << "PreparedStatement::set. index too large:" << index << std::endl;
    return ;
  }

  _bind[index].buffer_type = MYSQL_TYPE_DOUBLE;
  _bind[index].buffer = &value;
  _bind[index].is_unsigned = false;

}

void PreparedStatement::set(const int32 index, const string& value)
{
  if ( index >= _param_cnt ) {
    std::cout << "PreparedStatement::set. index too large:" << index << std::endl;
    return ;
  }

  _bind[index].buffer_type = MYSQL_TYPE_STRING;
  _bind[index].buffer = (char*)value.c_str();
  _bind[index].buffer_length = value.size();

}
