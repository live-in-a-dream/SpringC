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

	//�汾
	Http::CLHttpVersion version = Http::CLHttpVersion::HTTP1_1;

	//״̬��
	int state = 200;

	//״̬��Ϣ
	std::string stateMsg = "OK";

	//��Ӧͷ
	std::map<std::string, std::string> header;

	//body
	std::string body = "";

	std::string toString();

	//404��ַ
	static std::string to404();

	//������ַ
	static std::string toError(int state, ResponseMessage * responseMessage);


	//������ַ
	static std::string toError(ResponseMessage * responseMessage);


	std::string error = "";
private:

};
