#pragma once
#include <iostream>
#include <sstream>
#include <map>
#include "stringUtils.h"
#include "Http.h"
#include "ResponseMessage.h"

class HttpResponse
{
public:
	HttpResponse();
	virtual ~HttpResponse();

	//°æ±¾
	Http::CLHttpVersion version = Http::CLHttpVersion::HTTP1_1;

	//×´Ì¬Âë
	int state = 200;

	//×´Ì¬ĞÅÏ¢
	std::string stateMsg = "OK";

	//ÏìÓ¦Í·
	std::map<std::string, std::string> header;

	//body
	std::string body = "";

	std::string toString();

	//404ÍøÖ·
	static std::string to404();

	//´íÎóÍøÖ·
	static std::string toError(int state, ResponseMessage * responseMessage);


	//´íÎóÍøÖ·
	static std::string toError(ResponseMessage * responseMessage);


	std::string error = "";
private:

};
