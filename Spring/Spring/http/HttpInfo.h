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

	//«Î«Û
	HttpRequest httpRequest;

	//œÏ”¶
	HttpResponse httpResponse;
private:

};

