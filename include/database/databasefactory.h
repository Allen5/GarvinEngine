
#pragma once
#include <public.h>
#include <database/Database.h>

namespace GarvinEngine
{

	namespace Database
	{

		class DatabaseFactory
		{
			SINGLETON_DECALRE(DatabaseFactory);
		public:
			DBHandler* create(uint32 type);
		};

	}

}