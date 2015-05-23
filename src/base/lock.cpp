
#include <base/lock.h>

CLock::CLock()
{
#if defined(_WIN32) || defined(_WIN64)
  if ( !InitializeCriticalSectionAndSpinCount(&_section, 0x80000400) ) { //初始化锁，且使用旋转锁（具体参考windows核心编程）
    std::cout << "CLock(). InitializeCriticalSectionAndSpinCount. failed. " << GetLastError() << std::endl;
    return ;
  }
#else
  pthread_mutex_init(_mutex,NULL); //普通锁，后期可根据需求进行调整
#endif
}

CLock::~CLock()
{
#if defined(_WIN32) || defined(_WIN64)
  DeleteCriticalSection(&_section);
#else
  pthread_mutex_destroy(_mutex);
#endif
}

void CLock::lock()
{
#if defined(_WIN32) || defined(_WIN64)
  EnterCriticalSection(&_section);
#else
  pthread_mutex_lock(_mutex);
#endif
}

void CLock::unLock()
{
#if defined(_WIN32) || defined(_WIN64)
  LeaveCriticalSection(&_section);
#else
  pthread_mutex_unlock(_mutex);
#endif
}

#if !defined(_WIN32) && !defined(_WIN64)

bool CLock::tryLock()
{
  return pthread_mutex_trylock(_mutex) != EBUSY;
}

#endif

//////////////////////////////////////////////

AutoCriticalLock::AutoCriticalLock(CLock* lock)
  :_lock(NULL)
{
  if ( lock == NULL ) return ;

  _lock = lock;
  _lock->lock();
  
}

AutoCriticalLock::~AutoCriticalLock()
{
  if (_lock == NULL) return ;

  _lock->unLock();
  delete _lock;
  _lock = NULL;
  
}
