#pragma once
#include <string>
#include <iostream>
#include <functional>
#include <map>
#include "HttpRequest.h"
#include "HttpResponse.h"

class HttpInfo
{
public:
	HttpInfo();
	virtual ~HttpInfo();

	//����
	HttpRequest httpRequest;

	//��Ӧ
	HttpResponse httpResponse;
private:

};

