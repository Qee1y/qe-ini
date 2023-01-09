#include <iostream>

#include "iniparser.h"

int main()
{
	IniParser ini;
	ini.load("C:/Users/16493/Downloads/main.ini");
	ini.set("server", "quality", 1);
	const string& ip = ini["server"]["ip"];
	int port = ini.get("server", "port");
	bool flag = ini.get("server", "flag");
	
	bool hasFlag = ini.has("server");
	ini.Inishow();
	ini.save("C:/Users/16493/Downloads/main.ini");
	return 0;
}

