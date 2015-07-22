
#pragma once

#include <public.h>

//��ͷ�ļ���δ��linux�²��ԣ�windows�¿�������ȡ������
//��ʱֻ���쵱ǰʱ���
#include <sys/timeb.h>
#include <time.h>

class Datetime
{
  
public:  
    Datetime();
    virtual ~Datetime();

public:
  
    //��ȡ�����ַ�������ʽΪYYYY-MM-dd
    std::string getDate();

    //��ȡʱ���ַ�������ʽΪHH:MM:SS
    std::string getTime();

    //��ȡ����ʱ���ַ�������ʽΪ YYYY-MM-dd HH:MM:SS
    std::string getDateTime();

private:

    void _maketime(time_t now);

private:

    MEMBER_VARIABLE(uint64, timestamp);
    MEMBER_VARIABLE(uint16, year);
    MEMBER_VARIABLE(uint16, month);
    MEMBER_VARIABLE(uint16, day);
    MEMBER_VARIABLE(uint16, hour);
    MEMBER_VARIABLE(uint16, minute);
    MEMBER_VARIABLE(uint16, second);

};
