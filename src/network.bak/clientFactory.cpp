
#include <network/clientFactory.h>
#include <network/tcpclient.h>

using namespace GarvinEngine;
using namespace GarvinEngine::Network;

SINGLETON_DEFINE(ClientFactory)

Client* ClientFactory::create(uint32 proto)
{
	switch (proto) {
	case PROTO_TYPE_TCP: return new TCPClient();
	case PROTO_TYPE_UDP: return NULL;//todo new UDPClient();
	case PROTO_TYPE_HTTP: return NULL;//todo new HTTPClient();
	}
	return NULL;
}
