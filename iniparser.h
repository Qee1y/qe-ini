#pragma once

#include <map>

#include "ini.h"

typedef std::map<std::string, Value> Section;  //每个段

class IniParser
{
public:
	IniParser() {}
	string str();
	bool load(const string& filename);  //读取文件
	bool save(const string& filename);
	bool has(const string& section);    //查找节点
	bool has(const string& section, const string& key);  
	void Inishow();								 //显示节点
	void remove(const string& section);					 //删除节点
	void remove(const string& section, const string& key);
	void clear();
	

	Value get(const string& section, const string& key)
	{
		return m_section[section][key];
	}

	Section& operator[](const string& section)
	{
		return m_section[section];
	}

	template<typename T>
	void set(const string& section, const string& key, T value)
	{
		m_section[section][key] = value;
	}
private:
	string m_filename;
	std::map<string, Section> m_section;
};