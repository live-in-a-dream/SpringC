#include "HttpClient.h"

HttpClient::HttpClient()
{

}

HttpClient::~HttpClient()
{
	//线程中移除httpinfo
	std::map<std::thread::id, HttpInfo*>::iterator it = RequstProxy::getHttpInfoList()->find(clientRunThread->get_id());
	if (it != RequstProxy::getHttpInfoList()->end()) {
		RequstProxy::getHttpInfoList()->erase(it);
	}
}

void HttpClient::readData(std::string* data, std::string* error)
{
	/*
		请求解析
	*/
	HttpInfo httpInfo;
	httpInfo.httpRequest = HttpRequest(data);
	if ("" != httpInfo.httpRequest.error) {
		error = &httpInfo.httpRequest.error;
		//异常报错
		return;
	}

	HttpInfo httpInfoNew = httpInfo;

	//根据线程ID插入httpinfo
	RequstProxy::addHttpInfo(clientRunThread->get_id(), &httpInfo);

	//是否存在
	bool exist = false;
	for (auto it = RequstProxy::getRequstList()->begin(); it != RequstProxy::getRequstList()->end(); it++)
	{
		if (it->first == httpInfo.httpRequest.url) {
			/*
			if (!this) {
				continue;
			}*/
			exist = true;

			//业务逻辑运行前拦截
			for (int i =0;i< RequstProxy::getBusinessBeforeIntercept()->size();i++)
			{
				bool isBusinessBefore = RequstProxy::getBusinessBeforeIntercept()->at(i)(&httpInfoNew);
				//拦截成功直接返回
				if (isBusinessBefore) {
					httpInfo = httpInfoNew;
					sendSocket(httpInfo.httpResponse.toString().c_str());
					return;
				}
			}

			//回调
			it->second();

			//业务逻辑运行后-发送前-拦截
			for (int i = 0; i < RequstProxy::getSendBeforeIntercept()->size(); i++)
			{
				bool isSendBefore = RequstProxy::getSendBeforeIntercept()->at(i)(&httpInfoNew);
				//拦截成功直接返回
				if (isSendBefore) {
					httpInfo = httpInfoNew;
					sendSocket(httpInfo.httpResponse.toString().c_str());
					return;
				}
			}
			//发送
			sendSocket(httpInfo.httpResponse.toString().c_str());
		}
	}
	//找不到网页
	if (!exist) {
		sendSocket(HttpResponse::to404().c_str());
	}
}
