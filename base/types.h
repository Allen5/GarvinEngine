/**************************************************
 * filename: types.h
 * desc: defination of cross-platform type. like 'uint32'
 * Authro: Allen.Wu(allenlikeu@gmail.com)
 **************************************************/

#ifndef __BASE_TYPES_H__
#define __BASE_TYPES_H__

// 使用c++11的using来设定类型别名。更具可读性
#if !defined(int8)
using int8 = char;
#endif

#if !defined(uint8)
using uint8 = unsigned char;
#endif

#if defined(_WIN32) || defined(_WIN64)

#if !defined(int16)
using int16 = __int16;
#endif

#if !defined(uint16)
using uint16 = unsigned __int16;
#endif

#if !defined(int32)
using int32 = __int32;
#endif

#if !defined(uint32)
using uint32 = unsigned __int32;
#endif

#if !defined(int64)
using int64 = __int64;
#endif

#if !defined(uint64)
using uint64 = unsigned __uint64;
#endif

#else

#if !defined(int16)
using int16 = short;
#endif

#if !defined(uint16)
using uint16 = unsigned short;
#endif

#if SIZEOF_LONG == 8

#if !defined(int32)
using int32 = int;
#endif

#if !defined(uint32)
using uint32 = unsigned int;
#endif

#if !defined(int64)
using int64 = long;
#endif

#if !defined(uint64)
using uint64 = unsigned long;
#endif

#else

#if !defined(int32)
using int32 = long;
#endif

#if !defined(uint32)
using uint32 = unsigned long;
#endif

#if !defined(int64)
using int64 = long long;
#endif

#if !defined(uint64)
using uint64 = unsigned long long;
#endif

#endif // end for SIZEOF_LONG == 8

#endif // end for _WIN32 || _WIN64

#endif//__BASE_TYPES_H__
