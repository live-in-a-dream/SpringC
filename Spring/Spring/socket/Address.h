#pragma once
#ifndef ADDRESS_H
#define ADDRESS_H

#include <string>
#include <iostream>

#ifdef _WIN32
#include"winsock2.h"
#pragma comment(lib,"ws2_32.lib")
#elif __linux__

#elif __APPLE__

#endif


class Address {
public:
	Address(char*  ip = "0.0.0.0", int port = 8999);
	Address(int port = 8999);
	virtual ~Address();
	//ÓòÃû
	std::string hostname = "";
	//ip
	char * ip = "0.0.0.0";
	//¶Ë¿Ú
	int port = 8999;

private:

};

#endif