
/**
 * 此处定义跨平台公用函数，包括自定义的宏
 * @Date : 2015.05.02
 * @Author: Allen.Wu(allenlikeu@gmail.com)
 */

#if defined(_WIN32) || defined(_WIN64)
#define bzero(a, b) memset(a, 0, b);
#else
#include <strings.h>
#endif //跨平台支持bzero

#if defined(_WIN32) || defined(_WIN64)
#define CLOSE(sockfd) closesocket(sockfd)
#else
#define CLOSE(sockfd) close(sockfd)
#endif //cross-platform close file descriptor of socket

#if defined(_WIN32) || defined(_WIN64)
#define SLEEP(val) Sleep(val)
#else
#define SLEEP(val) \
{\
 struct timeval delay;\
 delay.tv_sec = 0;\
 delay.tv_usec = val * 1000;\
 select(0, NULL, NULL, NULL, &delay);\
}
#endif //跨平台毫秒级sleep支持

/**
 * 单例声明
 * note: restrictly speeking, singleton could not be inherrited or copied or assigned;
 */
#undef SINGLETON_DECALRE
#define SINGLETON_DECALRE(cls) \
private: static cls * _instance; \
private: cls(){ memset((void*)this, 0, sizeof(*this)); }	\
private: cls(const cls& var) { \
  if (&var == this) return; \
  memset((void*)this, 0, sizeof(*this)); \
  memcpy((void*)this, (void*)&var, sizeof(var)); \
} \
private: cls& operator = (const cls& var) { \
  if (&var == this) return *this; \
  memset((void*)this, 0, sizeof(*this)); \
  memcpy((void*)this, (void*)&var, sizeof(var)); \
  return *this; \
} \
public: static cls * getInstance() { if (_instance == NULL) _instance = new cls(); return _instance; }

//单例定义
#undef SINGLETON_DEFINE
#define SINGLETON_DEFINE(cls) \
cls * cls::_instance = NULL; 

//成员变量定义
#undef MEMBER_VARIABLE
#define MEMBER_VARIABLE(tpp, ppt) \
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

/**
 * 设置和返回指针类型的变量
 */
#undef MEMBER_POINT_VARIABLE
#define MEMBER_POINT_VARIABLE (tpp, ppt) \
private: tpp* _#ppt; \
public: void ppt(tpp* val) { _##ppt = val; } \
public: tpp* ppt() { return _##ppt; }

//TODO(allenlike@gmail): 此处需要补上常量指针，以及只读只写等情况。日后根据实际项目需求进行补充

/**
 * 设置和返回引用类型的变量
 */
#undef MEMBER_REF_VARIABLE
#define MEMBER_REF_VARIABLE (tpp, ppt) \
private: tpp& _##ppt; \
public: void ppt(tpp& val) { _##ppt = val; } \
public: tpp& ppt() { return _##ppt; }

//TODO(allenlike@gmail): 此处需要补上常量引用，以及只读只写等情况。日后根据实际项目需求进行补充
