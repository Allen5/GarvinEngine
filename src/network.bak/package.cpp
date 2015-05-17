
#include <network/package.h>

using namespace GarvinEngine;
using namespace GarvinEngine::Network;

Package::Package()
: _pos(0)
, _len(0)
, _size(MAX_BUF)
, _protoid(0)
{
	_buf = new int8[_size];
	memset(_buf, 0, _getBytes());
}

Package::Package(int8* data)
: _pos(0)
, _len(0)
, _size(MAX_BUF)
, _protoid(0)
{
	_len = getHeadLen(); //set _len == head length first
	_buf = new int8[_size];
	memcpy(_buf, data, _size);
	
	_protoid = readuint32();
	_len = readuint32(); //set _len == body length
}

Package::~Package()
{
	delete _buf;
	_buf = NULL;
}

int8 Package::readint8()
{
	int8 data = 0;
	assert(pos() + (uint32)sizeof(data) <= len());
	memcpy(&data, _buf + pos(), sizeof(data));
	pos(pos() + sizeof(data));
	return data;
}

uint8 Package::readuint8()
{
	uint8 data = 0;
	assert(pos() + (uint32)sizeof(data) <= len());
	memcpy(&data, _buf + pos(), sizeof(data));
	pos(pos() + sizeof(data));
	return data;
}

int16 Package::readint16()
{
	int16 data = 0;
	assert(pos() + (uint32)sizeof(data) <= len());
	memcpy(&data, _buf + pos(), sizeof(data));
	pos(pos() + sizeof(data));
	return ntohs(data);
}

uint16 Package::readuint16()
{
	uint16 data = 0;
	assert(pos() + (uint32)sizeof(data) <= len());
	memcpy(&data, _buf + pos(), sizeof(data));
	pos(pos() + sizeof(data));
	return ntohs(data);
}

int32 Package::readint32()
{
	int32 data = 0;
	assert(pos() + (uint32)sizeof(data) <= len());
	memcpy(&data, _buf + pos(), sizeof(data));
	pos(pos() + sizeof(data));
	return ntohl(data);
}

uint32 Package::readuint32()
{
	uint32 data = 0;
	assert(pos() + (uint32)sizeof(data) <= len());
	memcpy(&data, _buf + pos(), sizeof(data));
	pos(pos() + sizeof(data));
	return ntohl(data);
}

int64 Package::readint64()
{
	int64 data = 0;
	assert(pos() + (uint32)sizeof(data) <= len());
	memcpy(&data, _buf + pos(), sizeof(data));
	pos(pos() + sizeof(data));
	return _ntohi64(data);
}

uint64 Package::readuint64()
{
	uint64 data = 0;
	assert(pos() + (uint32)sizeof(data) <= len());
	memcpy(&data, _buf + pos(), sizeof(data));
	pos(pos() + sizeof(data));
	return _ntohi64(data);
}

float Package::readfloat()
{//float could ignore the issue of ending
	float data = 0.0f;
	assert(pos() + (uint32)sizeof(data) <= len());
	memcpy(&data, _buf + pos(), sizeof(data));
	pos(pos() + sizeof(data));
	return data;
}

double Package::readDouble()
{//the same as float
	double data = 0;
	assert(pos() + (uint32)sizeof(data) <= len());
	memcpy(&data, _buf + pos(), sizeof(data));
	pos(pos() + sizeof(data));
	return data;
}

std::string Package::readString()
{
	int32 nsize = readint32();
	assert((uint32)pos() + nsize <= len());

	int8 *buf = new int8[nsize];
	memcpy(buf, _buf + pos(), nsize);

	pos(pos() + nsize);
	return std::string(buf);
}

std::string Package::readUTF8()
{
	std::string buf = readString();
	//todo convert to UTF8
	return buf;
}

void Package::writeint8(const int8& data)
{
	if (pos() + (int32)sizeof(data) > _size) _extension(_buf);
	memcpy(_buf + pos(), &data, sizeof(data));
	pos(pos() + sizeof(data));
	_len = _pos;
}

void Package::writeuint8(const uint8& data)
{
	if (pos() + (int32)sizeof(data) > _size) _extension(_buf);
	memcpy(_buf + pos(), &data, sizeof(data));
	pos(pos() + sizeof(data));
	_len = _pos;
}

void Package::writeint16(const int16& data)
{
	if (pos() + (int32)sizeof(data) > _size) _extension(_buf);

	int16 var = htons(data);
	memcpy(_buf + pos(), &var, sizeof(var));
	pos(pos() + sizeof(var));
	_len = _pos;
}

void Package::writeuint16(const uint16& data)
{
	if (pos() + (int32)sizeof(data) > _size) _extension(_buf);
	
	uint16 var = htons(data);
	memcpy(_buf + pos(), &var, sizeof(var));
	pos(pos() + sizeof(var));
	_len = _pos;

}

void Package::writeint32(const int32& data)
{
	if (pos() + (int32)sizeof(data) > _size) _extension(_buf);

	int32 var = htonl(data);
	memcpy(_buf + pos(), &var, sizeof(var));
	pos(pos() + sizeof(var));
	_len = _pos;
}

void Package::writeuint32(const uint32& data)
{
	if (pos() + (int32)sizeof(data) > _size) _extension(_buf);

	uint32 var = htonl(data);
	memcpy(_buf + pos(), &var, sizeof(var));
	pos(pos() + sizeof(var));
	_len = _pos;
}

void Package::writeint64(const int64& data)
{
	if (pos() + (int32)sizeof(data) > _size) _extension(_buf);

	int64 var = _htoni64(data);
	memcpy(_buf + pos(), &var, sizeof(var));
	pos(pos() + sizeof(var));
	_len = _pos;
}

void Package::writeuint64(const uint64& data)
{
	if (pos() + (int32)sizeof(data) > _size) _extension(_buf);

	uint64 var = _htoni64(data);
	memcpy(_buf + pos(), &var, sizeof(var));
	pos(pos() + sizeof(var));
	_len = _pos;
}

void Package::writefloat(const float& data)
{
	if (pos() + (int32)sizeof(data) > _size) _extension(_buf);
	memcpy(_buf + pos(), &data, sizeof(data));
	pos(pos() + sizeof(data));
	_len = _pos;
}

void Package::writedouble(const double& data)
{
	if (pos() + (int32)sizeof(data) > _size) _extension(_buf);
	memcpy(_buf + pos(), &data, sizeof(data));
	pos(pos() + sizeof(data));
	_len = _pos;
}

void Package::writeString(const std::string& data)
{
	int32 n = data.length();
	writeint32(n);
	if (pos() + n > _size) _extension(_buf);
	memcpy(_buf + pos(), data.c_str(), n);
	pos(pos() + n);
	_len = _pos;
}

void Package::writeUTF8(const std::string& data)
{
	//todo
	//convert to UTF8
	writeString(data);
}

void Package::_extension(int8* data)
{//extension package when package size is not enough
	int8* temp = new int8[_size * 2];
	memset(temp, 0, _getBytes() * 2);
	memcpy(temp, data, _getBytes());
	
	delete data;
	data = NULL;

	data = temp;
	size(size() * 2);
}

int32 Package::_getBytes()
{
	return _size * sizeof(int8);
}

int64 Package::_ntohi64(int64 x)
{
	return ((int64)ntohl((uint32)(x << 32))) | ((int64)ntohl((uint32)(x >> 32)));
}

uint64 Package::_ntohi64(uint64 x)
{
	return (uint64)(ntohl((uint32)(x << 32)) | ntohl((uint32)(x >> 32)));
}

int64 Package::_htoni64(int64 x)
{
	return _ntohi64(x);
}

uint64 Package::_htoni64(uint64 x)
{
	return _ntohi64(x);
}

uint32 Package::getHeadLen()
{
	return sizeof(_protoid)+sizeof(_len);
}

uint32 Package::getBodyLen()
{
	return _len;
}

uint32 Package::getPackLen()
{
	return getHeadLen() + getBodyLen();
}

void Package::addPackHeader()
{
	if (_len + getHeadLen() > (uint32)_size) _extension(_buf);
	memmove(_buf + getHeadLen(), _buf, _len);
	memset(_buf, 0, getHeadLen());
	memcpy(_buf, &_protoid, sizeof(_protoid));
	memcpy(_buf, &_len, sizeof(_len));
}

