
/**
 * 处理网络数据大小端转换
 * @Date : 2015.05.02
 * @Author : Allen.Wu (allenlikeu@gmail.com)
 */

#define BUFFER_SIZE 4096

class Buffer
{
 public:
  Buffer();
  virtual ~Buffer();


 private:
  char _buf[BUFFER_SIZE];
  
};
