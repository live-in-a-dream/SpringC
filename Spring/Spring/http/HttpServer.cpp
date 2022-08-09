#include "HttpServer.h"

HttpServer::HttpServer()
{

}

HttpServer::~HttpServer()
{

}


//
void HttpServer::start() {
	//监听-并发支持10000
	bool isLisert = lister(10000);
	//监听失败
	if (!isLisert) {
		std::cout << error << std::endl;
		system("pause");
		return;
	}
	
	while (true)
	{
		//连接的客户端
		HttpClient* httpClient = new HttpClient;
		acceptSocket(httpClient);
		httpClient->run();
	}
}
