
#ifndef GARVINENGINE_BASE_THREAD_H
#define GARVINENGINE_BASE_THREAD_H

#include <public.h>

#if defined(_WIN32) || defined(_WIN64)
#include <windows.h> // for HANDLE
#define WIN32_LEAN_AND_MEAN
#include <process.h> // for _beginthread();
#else
#include <pthread.h>
#endif

class Thread
{
 public:

  Thread();
  virtual ~Thread();

  void start();		  //启动线程
  void stop();          //停止线程

  virtual void run() {};   //继承自thread的类，通过override此函数达到线程逻辑分离

  //创建线程时的入口点函数，此函数会验证参数是否为 Thread 类的实例，然后调用run()函数。
#if defined(_WIN32) || defined(_WIN64)
  static uint32 _stdcall entryPoint(void* obj);
#else
  static void* entryPoint(void* obj);
#endif
 private:

  void _init();
  uint32 _create();
  void _start();
  void _stop();

 private:
#if defined(_WIN32) || defined(_WIN64)
  HANDLE _thread;
  uint32 _threadID;
#else
  pthread_t _threadID;
#endif
};

#endif
