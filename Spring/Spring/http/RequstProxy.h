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
		���������map
	*/
	static std::map<const std::string, std::function<void()>>* requstList;

	/*
		�߳�ID->�������Ӧ
	*/
	static std::map<const std::thread::id, HttpInfo*>* httpInfoList;

	//ҵ���߼�����ǰ����
	static std::vector<std::function<bool(HttpInfo*)>>* businessBeforeIntercept;

	//ҵ���߼����к�-����ǰ-����
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

