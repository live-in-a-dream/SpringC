#pragma once
#include "ServerSocket.h"
#include <thread>
#include <map>
#include "HttpResponse.h"
#include "HttpRequest.h"
#include "HttpClient.h"
/*
	http�����
*/
class HttpServer : public ServerSocket
{
public:
	HttpServer();
	virtual ~HttpServer();



public:

	/*
		��������
	*/
	void start();

private:

};

