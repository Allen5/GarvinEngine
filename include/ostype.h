
/**
 * 此处用于定义跨平台的基本类型，如int8, int16等
 * @Date: 2015.05.02
 * @Author: Allen.Wu (allenlikeu@gmail.com)
 */

#pragma once

#if defined(_WIN32) || defined(_WIN64) //for windows

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

#else // for *nix

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

//define socket type
typedef int32 SOCKET;

