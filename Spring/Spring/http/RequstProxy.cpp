#include "RequstProxy.h"
std::map<const std::string, std::function<void()>>* RequstProxy::requstList = new std::map<const std::string, std::function<void()>>();

std::map<const std::thread::id, HttpInfo*>*  RequstProxy::httpInfoList = new std::map<const std::thread::id, HttpInfo*>();

//业务逻辑运行前拦截
std::vector<std::function<bool(HttpInfo*)>>* RequstProxy::businessBeforeIntercept = new std::vector<std::function<bool(HttpInfo*)>>();

//业务逻辑运行后-发送前-拦截
std::vector<std::function<bool(HttpInfo*)>>* RequstProxy::sendBeforeIntercept = new std::vector<std::function<bool(HttpInfo*)>>();

RequstProxy::RequstProxy()
{
}

RequstProxy::~RequstProxy()
{

}

void RequstProxy::addRequst(const std::string url, std::function<void()> requst)
{
	requstList->insert(std::map<const std::string, std::function<void()>>::value_type(url, requst));
}

void RequstProxy::addHttpInfo(std::thread::id tId, HttpInfo * httpInfo)
{
	httpInfoList->insert(std::map<const std::thread::id, HttpInfo *>::value_type(tId, httpInfo));
}

void RequstProxy::addBusinessBeforeIntercept(std::function<bool(HttpInfo*)> businessBefore)
{
	businessBeforeIntercept->push_back(businessBefore);
}

void RequstProxy::addSendBeforeIntercept(std::function<bool(HttpInfo*)> sendBefore)
{
	sendBeforeIntercept->push_back(sendBefore);
}

std::map<const std::string, std::function<void()>>* RequstProxy::getRequstList()
{
	return requstList;
}

std::map<const std::thread::id, HttpInfo*>* RequstProxy::getHttpInfoList()
{
	return httpInfoList;
}

std::vector<std::function<bool(HttpInfo*)>>* RequstProxy::getBusinessBeforeIntercept()
{
	return businessBeforeIntercept;
}

std::vector<std::function<bool(HttpInfo*)>>* RequstProxy::getSendBeforeIntercept()
{
	return sendBeforeIntercept;
}

HttpInfo * RequstProxy::getHttpInfo(const std::thread::id tId)
{
	return httpInfoList->at(tId);
}