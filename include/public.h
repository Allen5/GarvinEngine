
#pragma once

/**
 * 此处用于定义共用的跨平台类型、函数、宏等
 */
//常用头文件
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <assert.h>

#if defined(_WIN32) || defined(_WIN64)

#include <WinSock2.h>
#pragma comment(lib, "ws2_32.lib")

#else
#include <unistd.h>

typedef int32 SOCKET; 

#endif //跨平台 os基础库

#if defined(_WIN32) || defined(_WIN64)

#ifndef int8
typedef char int8;
#endif

#ifndef uint8
typedef unsigned char uint8;
#endif // !uint8

#ifndef int16
typedef __int16 int16;
#endif

#ifndef uint16
typedef unsigned __int16 uint16;
#endif

#ifndef int32
typedef __int32 int32;
#endif // !int32

#ifndef uint32
typedef unsigned __int32 uint32;
#endif

#ifndef int64
typedef __int64 int64;
#endif

#ifndef uint64
typedef unsigned __int64 uint64;
#endif


#else

#ifndef int8
typedef char int8;
#endif

#ifndef uint8
typedef unsigned char uint8;
#endif

#ifndef int16
typedef short int16;
#endif

#ifndef uint16
typedef unsigned short uint16;
#endif

#if SIZEOF_LONG == 8

#ifndef int32
typedef int int32;
#endif

#ifndef uint32
typedef unsigned int uint32;
#endif

#ifndef int64
typedef long int64;
#endif

#ifndef uint64
typedef unsigned long uint64;
#endif

#else

#ifndef int32
typedef long int32;
#endif

#ifndef uint32
typedef unsigned long uint32;
#endif

#ifndef int64
typedef long long int64;
#endif

#ifndef uint64
typedef unsigned long long uint64;
#endif

#endif //SIZEOF_LONG == 8

#endif //_WIN32 || _WIN64

//公共函数
#if defined(_WIN32) || defined(_WIN64)
#define bzero(a, b) memset(a, 0, b);
#else
#include <strings.h>
#endif //跨平台支持bzero

//单例声明
#undef SINGLETON_DECALRE
#define SINGLETON_DECALRE(cls) \
private: static cls * _instance; \
private: cls(){} \
private: cls(const cls&) {} \
private: cls& operator = (const cls&) {} \
public: virtual ~cls(){} \
public: static cls * getInstance() { if (_instance == NULL) _instance = new cls(); return _instance; }

//单例定义
#undef SINGLETON_DEFINE
#define SINGLETON_DEFINE(cls) \
cls * cls::_instance = NULL; 

//成员变量定义
#undef MEMBER_VARIBLE
#define MEMBER_VARIBLE(tpp, ppt) \
private: tpp _##ppt; \
public: void ppt(tpp val) { _##ppt = val; } \
public: tpp ppt() { return _##ppt; }

#undef MEMBER_READABLE
#define MEMBER_READABLE(tpp, ppt) \
private: tpp _##ppt; \
public: tpp ppt() { return _##ppt; }

#undef MEMBER_WRITABLE
#define MEMBER_WRITABLE(tpp, ppt) \
private: tpp _##ppt; \
public: tpp ppt() { return _##ppt; }
