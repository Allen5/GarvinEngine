
#pragma once

#include <public.h>

namespace GarvinEngine
{

	namespace Database
	{

		enum DatabaseType
		{

			DATABASE_TYPE_MYSQL = 1, //mysql

			DATABASE_TYPE_END,
		};

		class DBHandler
		{
			//todo
			//support execute, query, getConnection and getConnFrom connection pool
		};

	}

}