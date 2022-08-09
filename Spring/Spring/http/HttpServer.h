#pragma once
#include "ServerSocket.h"
#include <thread>
#include <map>
#include "HttpResponse.h"
#include "HttpRequest.h"
#include "HttpClient.h"
/*
	http服务端
*/
class HttpServer : public ServerSocket
{
public:
	HttpServer();
	virtual ~HttpServer();



public:

	/*
		启动服务
	*/
	void start();

private:

};

