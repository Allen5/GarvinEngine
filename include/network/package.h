
/**
 * support pack method and unpack method
 * handle with big ending and small ending
 */

#pragma once

#include <public.h>

namespace GarvinEngine
{

	namespace Network
	{

#define MAX_BUF 4096

		class Package
		{
		public:
			Package();
			Package(int8* data);
			virtual ~Package();

			uint32 getHeadLen();
			uint32 getBodyLen();
			uint32 getPackLen();
			void addPackHeader();

		public:

			int8	readint8();
			uint8	readuint8();
			int16	readint16();
			uint16	readuint16();
			int32	readint32();
			uint32	readuint32();
			int64	readint64();
			uint64	readuint64();
			float	readfloat();
			double	readDouble();
			std::string readString();
			std::string readUTF8();

			void writeint8(const int8& data);
			void writeuint8(const uint8& data);
			void writeint16(const int16& data);
			void writeuint16(const uint16& data);
			void writeint32(const int32& data);
			void writeuint32(const uint32& data);
			void writeint64(const int64& data);
			void writeuint64(const uint64& data);
			void writefloat(const float& data);
			void writedouble(const double& data);
			void writeString(const std::string& data);
			void writeUTF8(const std::string& data);

		private:
			void _extension(int8* data);
			int32 _getBytes();

			int64  _ntohi64(int64 x);
			int64  _htoni64(int64 x);

			uint64 _ntohi64(uint64 x);
			uint64 _htoni64(uint64 x);

		private:
			MEMBER_VARIBLE(int8*, buf);
			MEMBER_VARIBLE(int32, pos);
			MEMBER_VARIBLE(uint32, len);
			MEMBER_VARIBLE(int32, size);
			MEMBER_VARIBLE(uint32, protoid);
			MEMBER_VARIBLE(uint32, headlen);

		};

	}

}