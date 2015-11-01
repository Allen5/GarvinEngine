
/**
 * DBConn.初始化mysql访问，提供mysql query 和 non query 操作
 * @Date : 2015.05.06
 * @Author : Allen.Wu (allenlike@gmail.com)
 */

#pragma once

#include <mysql.h>
#include <public.h>
#include <database/resultset.h>

class DBConn
{
public:
    DBConn();
    virtual ~DBConn();
  
public:

    /**
     * 初始化mysql
     * @param const char* host, mysql 的ip地址
     * @param const int32 port, mysql 的端口
     * @param const char* username, mysql的用户名
     * @param const char* password, mysql的密码
     * @param const char* database, mysql的数据库名
     */
    void init(const char* host, const int32* port, const char* username, const char* password, const char* database);

    /**
     * 执行查询语句，并且返回结果集
     */
    ResultSet* query(const std::string& sql);

    /**
     * 执行非查询语句,返回执行是否成功
     * @return {true: success, false: failed}
     */
    bool execute(const std::string& sql);

private:

    MYSQL* _mysql;

    char* _host;
    int32 _port;
  
    char* _username;
    char* _database;
    char* _password;
  
};


