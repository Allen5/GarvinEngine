/**************************************************
 * filename: marcos.h
 * desc: defination of cross-platform marcos. like 'CLOSESOCKET'
 * Authro: Allen.Wu(allenlikeu@gmail.com)
 **************************************************/

#ifndef __BASE_MARCOS_H__
#define __BASE_MARCOS_H__

#if defined(_WIN32) || defined(_WIN64)
#define bzero(a, b) memset(a, 0, b);
#else
#include <strings.h>
#endif // 跨平台支持bzero

// *nix 需要引入unistd.h库
#if defined(_WIN32) || defined(_WIN64)
#define SLEEP(val) Sleep(val)
#else
#define SLEEP(val)                    \
  {                                   \
	struct timeval delay;             \
	delay.tv_sec = 0;                 \
	delay.tv_usec = val * 1000;       \
	select(0, NULL, NULL, NULL, &delay); \
  }
#endif

#define MEMBER_VARIABLE(tpp, ppt)                \
  private: tpp _##ppt;                           \
public: void ppt(tpp val) { _##ppt = val; }      \
public: tpp ppt() { return _##ppt; }             \

#define MEMBER_READABLE(tpp, ppt)               \
    private: tpp _##ppt;                        \
public: tpp ppt() { return _##ppt; }

#define MEMBER_WRITABLE(tpp, ppt)               \
    private: tpp _##ppt;                        \
public: tpp ppt() { return _##ppt; }

#define MEMBER_POINT_VARIABLE(tpp, ppt)        \
    private: tpp* _#ppt;                        \
public: void ppt(tpp* val) { _##ppt = val; }    \
public: tpp* ppt() { return _##ppt; }

#define MEMBER_REF_VARIABLE (tpp, ppt)          \
    private: tpp& _##ppt;                       \
public: void ppt(tpp& val) { _##ppt = val; }    \
public: tpp& ppt() { return _##ppt; }

#endif//__BASE_MARCOS_H__
