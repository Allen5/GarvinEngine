
#include <util/iniFileReader.h>

#include <regex>

using namespace std;
using namespace GarvinEngine::Util;

SINGLETON_DEFINE(IniFileReader)

void GarvinEngine::Util::IniFileReader::listSections(std::ifstream& in, std::vector<std::string> & vecSection)
{
	if (in.bad()) return;
	if (!in.is_open()) return;

	string rgx = "^\\[\\w*\\]$";
	regex exp(rgx);

	vecSection.clear();
	while (!in.eof())
	{
		char buf[1024] = { 0 };
		in.getline(buf, 1024);

		if (!regex_match(buf, exp)) continue;

		string section(buf);
		_remSectionFormat(section);//remove section format []
		vecSection.push_back(section);
	}

	in.clear();
	in.seekg(0, ios::beg);
}

void GarvinEngine::Util::IniFileReader::listKV(std::ifstream& in, const std::string& section, DataTable* table)
{

	if (in.bad()) return;
	if (!in.is_open()) return;

	bool beStart = false;

	DataRow* row = new DataRow();
	DataGrid* grid = NULL;

	string varSection = section;
	_addSectionFormat(varSection);//add section format []

	while (!in.eof())
	{
		char buf[1024] = { 0 };
		in.getline(buf, 1024);

		std::string content(buf);

		if (varSection == content){
			beStart = true;
			continue;
		}

		if (!beStart) continue;

		string::size_type pos = content.find("=");
		if (pos == content.npos) break;

		grid = new DataGrid(content.substr(0, pos), content.substr(pos + 1, (content.length() - pos)));
		row->add(grid);
	}

	table->add(section, row);

	in.clear();
	in.seekg(0, ios::beg);

}

void GarvinEngine::Util::IniFileReader::_remSectionFormat(std::string& section)
{
	section = section.substr(1, section.length() - 2);
}

void GarvinEngine::Util::IniFileReader::_addSectionFormat(std::string& section)
{
	section = "[" + section + "]";
}
