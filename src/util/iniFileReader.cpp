
#include <util/iniFileReader.h>

#include <regex>

using namespace std;
using namespace GarvinEngine::Util;

void GarvinEngine::Util::IniFileReader::listSections(std::ifstream& in, std::vector<std::string> & vecSection)
{
	if (in.bad()) return;
	if (in.is_open()) return;

	string rgx = "^\\[\\w*\\]$";
	regex exp(rgx);

	vecSection.clear();
	while (!in.eof())
	{
		char buf[1024] = { 0 };
		in.getline(buf, 1024);

		if (!regex_match(buf, exp)) continue;

		vecSection.push_back(buf);
	}

	in.clear();
	in.seekg(0, ios::beg);
}

void GarvinEngine::Util::IniFileReader::listKV(std::ifstream& in, const std::string& section, DataTable* table)
{

	if (in.bad()) return;
	if (in.is_open()) return;

	bool beStart = false;

	DataRow* row = NULL;
	DataGrid* grid = NULL;

	while (!in.eof())
	{
		char buf[1024] = { 0 };
		in.getline(buf, 1024);

		std::string content(buf);

		if (section == content && !beStart){
			beStart = true;
			continue;
		}

		if (!beStart) continue;

		string::size_type pos = content.find("=");
		if (pos == content.npos) continue;

		grid = new DataGrid(content.substr(0, pos), content.substr(pos + 1, (content.length() - pos)));
		row->add(grid);
	}

	table->add(section, row);

	in.clear();
	in.seekg(0, ios::beg);

}
