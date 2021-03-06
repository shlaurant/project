#include <iostream>


#include "MonsterFactory.h"
#include "Stat.h"

using std::string;
using std::vector;
using std::map;
using std::ifstream;
using std::cout;
using std::stoi;

// Data form in file 
// Monster name, Unit_Type, BASIC_ATK, BASIC_DEF, LEVEL, STR, INT, DEX, CON, LUK, giveExp, StringForm
Monster MonsterFactory::createMonster(std::string name)
{	
	//(Stirng, vector<string>) -> (String, int(status))
	// (vector<string>) -> (string)m_status
	map<Stat, int> status;
	
	auto status_monster_vec_in = m_monsters.at(name); 
	// for (Stat stat = Stat::UNIT_TYPE; stat < (Stat::EXP + 1) ;++stat);
	
	int status_iterator = static_cast<int>(Stat::UNIT_TYPE);
	
	// ele == status_in(string)
	for(auto & ele : status_monster_vec_in)
	{
		if(status_iterator != static_cast<int>(Stat::LAST))
		{	
			status[static_cast<Stat>(status_iterator)] = stoi(ele);
		}
		++status_iterator;
	}

	Monster created_monster(status);
	
	return created_monster;
	
	// string file = MonsterFactory::IOControl(filename);
	
	// auto monsters = IOControl(filename);
	
	// for(auto &ele : monsters)
	// {
		
	// }
}

void MonsterFactory::initMapUsing(const char* filename)
{
	
	{
		ifstream ifs(filename);
		
		while(ifs)
		{
			string str;
			getline(ifs, str);
			parseMonsterFrom(str);
		}
	}
}

void MonsterFactory::parseMonsterFrom(string str)
{
	string delimiter = ",";
	string value;
	string key;
	vector<string> monster_status;
	
// 	map<string, vector<string>> monster;
	
	size_t pos = 0;
	
	if((pos = str.find(delimiter)) != string::npos)
	{
		key = str.substr(0, pos);
		str.erase(0, pos + delimiter.length());
	}
	
	while((pos = str.find(delimiter)) != string::npos)
	{
		value = str.substr(0, pos);
		monster_status.push_back(value);
		str.erase(0, pos + delimiter.length());
	}
	
	monster_status.push_back(str);
	
	m_monsters[key] = monster_status;
}