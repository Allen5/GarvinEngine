
#pragma once

/**
 * �˴����ڶ��干�õĿ�ƽ̨���͡����������
 */
//����ͷ�ļ�
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <list>
#include <assert.h>

#if defined(_WIN32) || defined(_WIN64)
#include <WinSock2.h>
#pragma comment(lib, "ws2_32.lib")
#include <windows.h>
#else
#include <unistd.h>
#endif //��ƽ̨ os������

#include "ostype.h" //��ƽ̨���Ͷ���
#include "pubfunc.h"//��ƽ̨��������

