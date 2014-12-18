
#pragma once

#include <network/tcpsimpleserver.h>

using namespace GarvinEngine;
using namespace GarvinEngine::Network;


bool TCPSimpleServer::open()
{
	if (!_bind()) return false;

	sockaddr_in clientaddr;
	while (true)
	{
		Session* session = _accept(clientaddr);
		addSession(session);

		Request* request = session->recv();
		process(session, request);
	}

	return true;
}