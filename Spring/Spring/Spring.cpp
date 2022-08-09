// Spring.cpp: 定义应用程序的入口点。
//

#include "Spring.h"
#include "ServerSocket.h"
#include <thread>
#include <map>
#include "HttpRequest.h"
#include "HttpResponse.h"
#include "HttpServer.h"
#include "ClientSocket.h"
#include "HttpClient.h"
#include <utility>

int main()
{

	HttpServer* serverSocket = new HttpServer;

	RequstProxy::addBusinessBeforeIntercept([=](HttpInfo * httpInfo) {
		//解析Token把用户放入请求头
		return false;
		});

	RequstProxy::addSendBeforeIntercept([=](HttpInfo * httpInfo) {
		httpInfo->httpResponse.body = "我拦截了";
		return false;
		});

	RequstProxy::addRequst("/word", [=]() {
		HttpInfo* httpInfo = RequstProxy::getHttpInfo();
		httpInfo->httpResponse.body = "word";
		std::cout << "接受成功" << std::endl;
		});

	RequstProxy::addRequst("/hello", [=]() {
		HttpInfo* httpInfo = RequstProxy::getHttpInfo();
		httpInfo->httpResponse.body = "hello";
		std::cout << "接受成功" << std::endl;
		});

	serverSocket->start();

	system("pause");
	return 0;
}
