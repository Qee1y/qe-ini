#include <fstream>
#include <iostream>

#include "iniparser.h"


string IniParser::str()
{
	std::stringstream ss;
	for (auto it : m_section)
	{
		ss << "[" << it.first << "]\n";
		for (auto iter : it.second)
		{
			ss << iter.first << " = " << string(iter.second) << "\n";
		}
	}
	return ss.str();
}

bool IniParser::load(const string& filename)
{
	m_filename = filename;
	std::ifstream in(filename);
	if (in.fail())
		return false;

	string line;
	string section;
	while (std::getline(in, line))
	{
		if (line == "")
			continue;
		if (line[0] == '[')
		{
			int pos = line.find_first_of(']');  
			section = line.substr(1, pos - 1);
			m_section[section] = Section();
		}
		else
		{
			int pos = line.find_first_of('=');
			string key = line.substr(0, pos - 1);
			string value = line.substr(pos + 2, line.length());
			m_section[section][key] = value;
		}
	}
	in.close();
	return true;
}

bool IniParser::save(const string& filename)
{
	std::ofstream out(filename);
	if (out.fail())
	{
		return false;
	}
	out << str();
	out.close();
	return true;
}

bool IniParser::has(const string& section)
{
	return m_section.find(section) != m_section.end();
}

bool IniParser::has(const string& section, const string& key)
{
	auto it = m_section.find(section);
	if (it != m_section.end())  //当find没有找到key，会返回end()迭代器
	{
		return it->second.find(key) != it->second.end();
	}
	return false;
}

void IniParser::remove(const string& section)
{
	m_section.erase(section);
}

void IniParser::remove(const string& section, const string& key)
{
	auto it = m_section.find(section);
	if (it != m_section.end())
		it->second.erase(key);
}

void IniParser::clear()
{
	m_section.erase(m_section.begin(), m_section.end());
}

void IniParser::Inishow() 
{
	std::cout << str();
}