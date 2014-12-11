
#include <iostream>
#include <config/configFactory.h>
#include <direct.h>

using namespace std;

int main(int argc, char** argv)
{

	char workdir[128] = { 0 };
	_getcwd(workdir, sizeof(workdir));

	std::string path = "G:\\test.ini"; //std::string(workdir) + "\\test.ini";
	cout << path << endl;

	ConfigLoaderBase* loader = ConfigFactory::getInstance()->create(CONFIG_FILE_TYPE_INI, path);
	
	DataTable* table = NULL;
	if (!loader->load()) {
		cout << "test.ini file read error" << endl;
		goto END;
	}
	table = loader->get();

	cout << table->count() << endl;
	cout << "[section]" << endl;

	DataRow* row = table->getRow("[section]");
	cout << row->count() << endl;
	cout << row->getField(0) << "=" << row->getString(row->getField(0)) << endl;

END:
#if defined(_WIN32) || defined(_WIN64)
	system("pause");
#endif
	return 0;
}