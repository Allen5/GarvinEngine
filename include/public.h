
#pragma once

/**
 * 此处用于定义共用的跨平台类型、函数、宏等
 */
//常用头文件
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <list>
#include <assert.h>

#if defined(_WIN32) || defined(_WIN64)
#include <WinSock2.h>
#pragma comment(lib, "ws2_32.lib")
#include <windows.h>
#else
#include <unistd.h>
#endif //跨平台 os基础库

#include "ostype.h" //跨平台类型定义
#include "pubfunc.h"//跨平台函数定义

