
/**
 * 基于网络模型处理事件分发
 * @Date : 2015.05.02
 * @Author: Allen.Wu (allenlikeu@gmail.com)
 */

#include <public.h>


class EventDispatch
{

  SINGLETON_DECALRE(EventDispatch);

 public:

  bool start();

  bool stop();
  
};
