
#include <base/thread.h>

using namespace GarvinEngine;
using namespace GarvinEngine::Util;


void Thread::start()
{
	_start();
}

void Thread::stop()
{
	_stop();
}

#if defined(_WIN32) || defined(_WIN64)
uint32 _stdcall Thread::entryPoint(void* obj)
{
	Thread* pthis = static_cast<Thread*>(obj);
	pthis->run();
	return 1;
}
#else
void* Thread::entryPoint(void* obj)
{
	Thread* pthis = static_cast<Thread*>(obj);
	pthis->run();
	return NULL;
}
#endif

void Thread::_init()
{
#if defined(_WIN32) || defined(_WIN64)
	_thread = NULL;
	_threadID = 0;
#else
	memset(&_threadID, 0, sizeof(_threadID));
#endif
}

uint32 Thread::_create()
{
#if defined(_WIN32) || defined(_WIN64)
	_thread = (HANDLE)_beginthreadex(
		NULL,				//Ȩ��
		0,					//ջ��С
		Thread::entryPoint, //��ں���
		this,				//����
		CREATE_SUSPENDED,	//����ʱ���ȹ���
		&_threadID);

	if (_thread == NULL) return 0; //0: ����ʧ��

	return _threadID;
#else

	unsigned int ret = pthread_create(&_threadID, NULL, entryPoint, this);
	if (ret != 0) {
		//log error
		//cout << "pthread_create failed(), error : " << endl;
		return 0;
	}
	return 1;

#endif
}

void Thread::_start()
{
#if defined(_WIN32) || defined(_WIN64)
	ResumeThread(_thread);			//�����߳�
	WaitForSingleObject(_thread, (DWORD)INFINITY);
#else
	pthread_join(_threadID, NULL);
#endif
}

void Thread::_stop()
{
#if defined(_WIN32) || defined(_WIN64)
	//ֹͣ�߳�
	CloseHandle(_thread);
#else
	pthread_exit(NULL);
#endif
}

Thread::Thread()
{
	_init();
	if (!_create()) { //�������ڹ��캯������ֹ��һ���������ظ��߳�
		//cout << "create thread failed()" << endl;
		//log sth
		return;
	}
}

Thread::~Thread()
{
	this->_stop();
}
