

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
