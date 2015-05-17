
/**
 * 此处定义数据读写
 * @Date : 2015.05.02
 * @Author : Allen.Wu (allenlikeu@gmail.com)
 */

enum SocketType
{
  SOCKET_TYPE_TCP  = 0x01,
  SOCKET_TYPE_UDP  = 0x02,
  SOCKET_TYPE_HTTP = 0x03,
  SOCKET_TYPE_END,
};

enum SocketState
{
  SOCKET_STATE_CONNECT     = 0x01,
  SOCKET_STATE_ESTABLISHED = 0x02,
  SOCKET_STATE_CLOSED      = 0x03,
  SOCKET_STATE_END,
}

class Socket
{
 public:
  Socket();
  virtual ~CSocket();

 public:

  void onRead();
  void onWrite();
  void onConnect();
  void onClose();

 private:

  uint8 _socket_state;
  
};
