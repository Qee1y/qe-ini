#pragma once

#include <string>
#include <sstream>

using std::string;

class Value
{
public:
	Value();

	template <typename T>
	Value(T value)
	{
		*this = value;
	}

	template <typename T>
	Value & operator=(T value)
	{
		std::stringstream ss;
		ss << std::boolalpha;
		ss << value;
		m_value = ss.str();
		return *this;
	}

	operator bool();
	operator int();
	operator double();
	operator string();
private:
	string m_value;
};
