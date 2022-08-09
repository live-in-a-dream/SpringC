#pragma once


#include <string>
#include <iostream>
#include <functional>
#include <map>
#include "CLSocket.h"
#include "HttpRequest.h"
#include <thread>
#include "HttpInfo.h"
class RequstProxy
{
public:
	RequstProxy();
	virtual ~RequstProxy();


private:

	/*
		所有请求的map
	*/
	static std::map<const std::string, std::function<void()>>* requstList;

	/*
		线程ID->请求和响应
	*/
	static std::map<const std::thread::id, HttpInfo*>* httpInfoList;

	//业务逻辑运行前拦截
	static std::vector<std::function<bool(HttpInfo*)>>* businessBeforeIntercept;

	//业务逻辑运行后-发送前-拦截
	static std::vector<std::function<bool(HttpInfo*)>>* sendBeforeIntercept;


public:
	static void addRequst(const std::string, std::function<void()>);

	static void addHttpInfo(const std::thread::id, HttpInfo*);

	static void addBusinessBeforeIntercept(std::function<bool(HttpInfo*)>);

	static void addSendBeforeIntercept(std::function<bool(HttpInfo*)>);

public:

	static std::map<const std::string, std::function<void()>>* getRequstList();

	static std::map<const std::thread::id, HttpInfo*>*  getHttpInfoList();

	static std::vector<std::function<bool(HttpInfo*)>>* getBusinessBeforeIntercept();

	static std::vector<std::function<bool(HttpInfo*)>>* getSendBeforeIntercept();

public:
	static HttpInfo* getHttpInfo(const std::thread::id = std::this_thread::get_id());
private:

};

