#include "ini.h"

Value::Value() {}

Value::operator bool()
{
	return m_value == "true";
}

Value::operator int()
{
	return std::atoi(m_value.c_str());
}

Value::operator double()
{
	return std::atof(m_value.c_str());
}

Value::operator std::string()
{
	return m_value;
}