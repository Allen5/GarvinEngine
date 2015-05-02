
/**
 * 跨平台锁的实现，并提供简易加锁，解锁的类
 * @Date : 2015.05.02
 * @Author: Allen.Wu (allenlikeu@gmail.com)
 */

#pragma once

#include <public.h>

class CLock
{
 public:

  CLock();
  virtual ~CLock();

 public:

  void lock();
  void unLock();

#if !defined(_WIN32) && !defined(_WIN64)
  virtual bool tryLock();
#endif

 private:

#if defined(_WIN32) || defined(_WIN64)
  CRITICAL_SECTION _section;
#else
  pthread_mutex_t* _mutex;
#endif

  
};

/**
 * 简易临界锁类。
 * 构造时加锁，析构时解锁
 */
class AutoCriticalLock
{
 public:
  AutoCriticalLock(CLock* lock);
  virtual ~AutoCriticalLock();

 private:
  CLock* _lock;
};
