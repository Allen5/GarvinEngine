
#include <network/tcpnonblockserver.h>
#include <network/serverFactory.h>
#include <network/netcommon.h>

using namespace GarvinEngine;
using namespace GarvinEngine::Network;

SINGLETON_DEFINE(ServerFactory);

Server* ServerFactory::create(int32 serverType, int32 protoType)
{
	assert(serverType >= SERVER_TYPE_THREAD && serverType < SERVER_TYPE_END);
	if (serverType == SERVER_TYPE_THREAD)
	{
		switch (protoType)
		{
		case PROTO_TYPE_TCP: return NULL;//todo return new TCPThreadServer();
		case PROTO_TYPE_UDP: return NULL;//todo return new UDPThreadServer();
		case PROTO_TYPE_HTTP: return NULL;//todo return new HTTPThreadServer();
		}
		return NULL;
	}

	if (serverType == SERVER_TYPE_PROCESS)
	{
		switch (protoType)
		{
		case PROTO_TYPE_TCP: return NULL;//todo return new TCPProcessServer();
		case PROTO_TYPE_UDP: return NULL;//todo return new UDPProccessServer();
		case PROTO_TYPE_HTTP: return NULL;//todo return new HTTPProcesseServer();
		}
		return NULL;
	}

	if (serverType == SERVER_TYPE_NON_BLOCK)
	{
		switch (protoType)
		{
		case PROTO_TYPE_TCP: return new TCPNonblockServer();
		case PROTO_TYPE_UDP: return NULL;//todo return new UDPNonblockServer();
		case PROTO_TYPE_HTTP: return NULL;//todo return new HTTPNonblockServer();
		}
		return NULL;
	}

	return NULL;
}
