
#include <network/session.h>

using namespace GarvinEngine;
using namespace GarvinEngine::Network;

Session::Session()
: _sid(0)
, _ip("")
, _port(0)
, _loginTime(0)
, _sockfd(0)
{
}


Session::~Session()
{

}

bool Session::halt()
{
	//close connection
#if defined(_WIN32) || defined(_WIN64)
	int32 ret = shutdown(sockfd(), SD_BOTH);//make sure data was send
#else
	int32 ret = shutdown(sockfd(), SHUT_RDWR);
#endif
	if (ret == -1) {
		//todo
		//log it
		return false;
	}
	CLOSE(sockfd());
	return true;
}

