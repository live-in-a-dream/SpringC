#pragma once
#include <iostream>
#include <map>
#include "stringUtils.h"



class Http
{
public:
	Http();
	virtual ~Http();

	//·½·¨
	enum CLHttpMethod
	{
		//GET
		GET,
		//POST
		POST,
		//PUT
		PUT,
		//HEAD
		HEAD,
		METHOD_NONE,
	};

	//°æ±¾
	enum CLHttpVersion
	{
		HTTP1_0,
		HTTP1_1,
		VERSION_NONE,
	};


	//
	static Http::CLHttpMethod strToCLHttpMethod(std::string str, std::string* error);

	//
	static void strToQueryParam(std::map<std::string, std::string>* queryParam, std::string* url, std::string* error);

	//
	static Http::CLHttpVersion strToHttpVersion(std::string str, std::string* error);

	//
	static std::string HttpVersionTostr(Http::CLHttpVersion version, std::string* error);

private:

};

