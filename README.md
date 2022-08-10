

 	HttpServer* serverSocket = new HttpServer;

	RequstProxy::addBusinessBeforeIntercept([=](HttpInfo * httpInfo) {
		//解析Token把用户放入请求头
		return false;
		});

	RequstProxy::addSendBeforeIntercept([=](HttpInfo * httpInfo) {
		httpInfo->httpResponse.body = "我拦截了";
		return false;
		});

	RequstProxy::addErrorIntercept([=](Exception * e, HttpInfo* httpInfo) {
		if (NotHttpException* exception = dynamic_cast<NotHttpException*>(e)) {
			httpInfo->httpResponse.body = "NotHttpException";
		}
		if (UnsupportedHttpException* exception = dynamic_cast<UnsupportedHttpException*>(e)) {
			httpInfo->httpResponse.body = "UnsupportedHttpException";
		}
		if (HttpHeaderException* exception = dynamic_cast<HttpHeaderException*>(e)) {
			httpInfo->httpResponse.body = "HttpHeaderException";
		}
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
