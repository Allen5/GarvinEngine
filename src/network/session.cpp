
#include <network/session.h>

using namespace GarvinEngine;
using namespace GarvinEngine::Network;

Session::Session()
:_sid(0)
, _ip("")
, _port(0)
, _loginTime(0)
, _sockfd(0)
{
}


Session::~Session()
{

}

Request* Session::recv()
{
	//todo
	//receive data and convert to Request;
	return NULL;
}

void Session::send(Response* resp)
{
	//todo 
	//send Response to requestor
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
	closesocket(sockfd());
	return true;
}

