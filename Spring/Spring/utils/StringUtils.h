#pragma once
#pragma once
#ifndef STRINGUTILS_H
#define STRINGUTILS_H

#include <string>
#include <iostream>
#include <vector>
#include <array>
#include <sstream>

class StringUtils
{
public:
	StringUtils();
	~StringUtils();


	//·Ö¸î
	static std::vector<std::string> StringUtils::split(std::string* data, const char * separator);

private:

};



#endif