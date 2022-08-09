#pragma once
#include "CLSocket.h"
#include <iostream>
#include <thread>
#include "RequstProxy.h"
#include "HttpRequest.h"

/*
	socket客户端
*/
class ClientSocket : public CLSocket
{
public:
	ClientSocket();
	virtual ~ClientSocket();

public:
	virtual void readData(std::string* data, std::string* error) {};

	/*
		运行线程跑
	*/
	virtual void run();
public:
	/*
		关闭继承
	*/
	virtual void CloseSocket() override;





	std::thread * clientRunThread;
private:

};

