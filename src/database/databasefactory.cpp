
#include <database/databasefactory.h>
#include <database/mysqlhandler.h>

using namespace GarvinEngine;
using namespace GarvinEngine::Database;

SINGLETON_DEFINE(DatabaseFactory)


DBHandler* DatabaseFactory::create(uint32 type)
{
	switch (type)
	{
	case DATABASE_TYPE_MYSQL: return new MySQLHandler();
	}
	return NULL;
}
