#pragma once
#include "CLSocket.h"
#include <iostream>
#include <thread>
#include "RequstProxy.h"
#include "HttpRequest.h"

/*
	socket�ͻ���
*/
class ClientSocket : public CLSocket
{
public:
	ClientSocket();
	virtual ~ClientSocket();

public:
	virtual void readData(std::string* data, std::string* error) {};

	/*
		�����߳���
	*/
	virtual void run();
public:
	/*
		�رռ̳�
	*/
	virtual void CloseSocket() override;





	std::thread * clientRunThread;
private:

};

