
#ifndef GARVINENGINE_UTIL_XSTRING_H
#define GARVINENGINE_UTIL_XSTRING_H

/**
 * ���ڴ���string �� int,double,float֮�����͵�ת��
 * Ŀǰ��֧��10���Ƶ�string����Ҫ�޸�������ʽ��֧��16���ƣ�8���Ƶ�string���ݡ�
 * ����2015.05.26ǰ��ɣ��������ز��԰���
 * @Author : Allen.Wu(allenlikeu@gmail.com)
 * @Date : 2015.05.24
 */

#include <public.h>

class XString
{
		
  SINGLETON_DECALRE(XString);

 public:

  void translate(const std::string& from, int8&	  to);
  void translate(const std::string& from, uint8&  to);
  void translate(const std::string& from, int16&  to);
  void translate(const std::string& from, uint16& to);
  void translate(const std::string& from, int32&  to);
  void translate(const std::string& from, uint32& to);
  void translate(const std::string& from, int64&  to);
  void translate(const std::string& from, uint64& to);
  void translate(const std::string& from, float&  to);
  void translate(const std::string& from, double& to);

  std::string toString(const int8&		from);
  std::string toString(const uint8&		from);
  std::string toString(const int16&		from);
  std::string toString(const uint16&		from);
  std::string toString(const int32&		from);
  std::string toString(const uint32&		from);
  std::string toString(const int64&		from);
  std::string toString(const uint64&		from);
  std::string toString(const float&		from);
  std::string toString(const double&		from);

  //should add toUTF8 interface

  //should add toGBK interface

 private:

  //check whether str is legal
  bool _checkNumber(std::string str);
};


#endif
