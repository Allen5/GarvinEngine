
#include <network/request.h>

using namespace GarvinEngine;
using namespace GarvinEngine::Network;

Request::Request()
{
}

Request::Request(Package* pack)
{
	_pack = pack;
	protoID(_pack->protoid());
}
