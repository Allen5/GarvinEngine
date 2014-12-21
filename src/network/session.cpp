
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

bool Session::close()
{
	//close connection
	int32 ret = shutdown(sockfd(), SD_BOTH);//make sure data was send
	if (ret == -1) {
		//todo
		//log it
		return false;
	}
	CLOSE(sockfd());
	return true;
}

