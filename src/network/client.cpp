
#include <network/client.h>
#include <util/logger.h>

using namespace GarvinEngine;
using namespace GarvinEngine::Network;
using namespace GarvinEngine::Util;


Client::Client()
: _ip("")
, _port(0)
, _sockfd(0)
, _reconnInner(3)
, _closeHandler(NULL)
{
	_handlers.clear();
}

Client::~Client()
{
	delete _closeHandler;
	_closeHandler = NULL;

	std::map<uint32, Handler*>::iterator iter = _handlers.begin();
	for (; iter != _handlers.end(); iter++) delete iter->second;
}

void Client::close()
{
	int32 ret = shutdown(_sockfd, SD_BOTH);
	if (ret < 0) {
		std::cout << "Client::close() shutdown failed." << std::endl;
	}
	CLOSE(_sockfd);
	return ;
}

void Client::onResponse(uint32 proto, Handler* handler)
{
	_handlers[proto] = handler;
}

void Client::onNotify(uint32 proto, Handler* handler)
{
	_handlers[proto] = handler;
}

void Client::onClose(Handler* handler)
{
	_closeHandler = handler;
}

void Client::process(Response* resp)
{
	if (resp == NULL) { //server is down or something wrong
		_closeHandler->handle(resp);
		close();
		return;
	}

	std::map<uint32, Handler*>::iterator iter = _handlers.find(resp->protoID());
	iter->second->handle(resp);

}

void Client::run()
{
	//receive message from sever
	//and call process
}
