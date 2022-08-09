#ifndef SERVERSOCKET_H
#define SERVERSOCKET_H

#pragma once
#include "CLSocket.h"
#include "ClientSocket.h"
#include <iostream>

/*
	socket�����
*/
class ServerSocket : public CLSocket {
public:
	ServerSocket();
	virtual ~ServerSocket();
	/*
		����
	*/
	bool lister(int backlog = 1);
	/*
		�ȴ����ܿͻ�������
	*/
	void acceptSocket(CLSocket* clientCLSocket);

	//��ʱʱ�� s��   1s * 60 * 1 = 1����
	int readTime = 1000 * 60 * 10;

	//��ʱʱ�� s�� 1s * 60 * 1 = 1����
	int sendTime = 1000 * 60 * 10;
};

#endif