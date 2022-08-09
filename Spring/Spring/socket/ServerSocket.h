#ifndef SERVERSOCKET_H
#define SERVERSOCKET_H

#pragma once
#include "CLSocket.h"
#include "ClientSocket.h"
#include <iostream>

/*
	socket服务端
*/
class ServerSocket : public CLSocket {
public:
	ServerSocket();
	virtual ~ServerSocket();
	/*
		监听
	*/
	bool lister(int backlog = 1);
	/*
		等待接受客户端连接
	*/
	void acceptSocket(CLSocket* clientCLSocket);

	//超时时间 s秒   1s * 60 * 1 = 1分钟
	int readTime = 1000 * 60 * 10;

	//超时时间 s秒 1s * 60 * 1 = 1分钟
	int sendTime = 1000 * 60 * 10;
};

#endif