#include "HttpServer.h"

HttpServer::HttpServer()
{

}

HttpServer::~HttpServer()
{

}


//
void HttpServer::start() {
	//����-����֧��10000
	bool isLisert = lister(10000);
	//����ʧ��
	if (!isLisert) {
		std::cout << error << std::endl;
		system("pause");
		return;
	}
	
	while (true)
	{
		//���ӵĿͻ���
		HttpClient* httpClient = new HttpClient;
		acceptSocket(httpClient);
		httpClient->run();
	}
}
