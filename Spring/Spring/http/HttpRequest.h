#pragma once

#include <iostream>
#include <sstream>
#include <map>
#include "stringUtils.h"
#include "Http.h"

class HttpRequest
{
public:
	HttpRequest();
	HttpRequest(std::string* data);
	virtual ~HttpRequest();

	//
	std::string* data;

	//请求头
	std::map<std::string, std::string> header;

	//参数
	std::map<std::string, std::string> queryParam;

	//方法
	Http::CLHttpMethod method;

	//网址
	std::string url;

	//版本
	Http::CLHttpVersion version;

	//body
	std::string body;

	//主机
	std::string host = "";

	//报错信息
	std::string error = "";

	//解析
	void analysis(std::string* data);
private:

};

