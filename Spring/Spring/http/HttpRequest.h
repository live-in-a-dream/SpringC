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

	//����ͷ
	std::map<std::string, std::string> header;

	//����
	std::map<std::string, std::string> queryParam;

	//����
	Http::CLHttpMethod method;

	//��ַ
	std::string url;

	//�汾
	Http::CLHttpVersion version;

	//body
	std::string body;

	//����
	std::string host = "";

	//������Ϣ
	std::string error = "";

	//����
	void analysis(std::string* data);
private:

};

