#pragma once
#ifndef CLSOCKET_H
#define CLSOCKET_H

#include <string>
#include <iostream>
#include <functional>
#include <sstream>
#include "Address.h"
#include "StringUtils.h"
#include <thread>
#include "HttpResponse.h"
#ifdef _WIN32
//��ַϵ��
enum CLSocketDomain
{
	//AF_LOCAL����ͨ��
	UNIX = AF_UNIX,
	//IPv4����ͨ��
	INET = AF_INET,
	//IPv6����ͨ��
	INET6 = AF_INET6,
};

//�׽�������
enum CLSocketType
{
	//A���׽���, �ṩ˳�򣬿ɿ���˫�򣬻������ӵ��ֽ����� ����֧�ִ������ݴ�����ơ����磺TCPЭ�顢FTPЭ��
	STREAM = SOCK_STREAM,
	//���ݰ��׽���, ֧�����ݱ��������ӣ����ɿ��Ĺ̶���󳤶ȵ���Ϣ�����磺UDPЭ��
	DGRAM = SOCK_DGRAM,
	//ԭʼ�׽���, ʹ��ԭʼ�׽���ʱ����ã�ԭʼ�׽���Ҳ������·��Э��
	RAW = SOCK_RAW,
	//��������׽���,Ϊ�̶���󳤶ȵ����ݱ��ṩ���򣬿ɿ���˫�����ӵ����ݴ���·��; ��������Ҫ����ÿ������ϵͳ���ö�ȡ��������
	SEQPACKET = SOCK_SEQPACKET,
};

//Э���
enum CLSocketProtocol
{
	//TCPЭ��
	TCP = IPPROTO_TCP,

};
#elif __linux__

#elif __APPLE__

#endif

class CLSocket{
public:
	CLSocket();
	virtual ~CLSocket();

public:

	//��ַ
	Address address = Address("0.0.0.0", 8999);
	//��ַϵ��
	CLSocketDomain domain = CLSocketDomain::INET;
	//�׽�������
	CLSocketType type = CLSocketType::STREAM;
	//Э���
	CLSocketProtocol protocol = CLSocketProtocol::TCP;


	//����
	std::string error = "";

	//�Ƿ�ر�
	bool isClose = false;

public:

	/*
		�������Ͷ˿�
	*/
	bool bindSocket(Address* address);

	/*
		������Ϣ
	*/
	bool sendSocket(const char * data,int len);

	/*
		������Ϣ
	*/
	bool sendSocket(const char * data);

	/*
		��ȡ��Ϣ
	*/
	std::string CLSocket::readSocket();

	/*
		�ر�
	*/
	void close();

/*
	��������
*/
public:
	virtual void CloseSocket() {};


public:
	#ifdef _WIN32
		SOCKET clSocket;
		/*
		 ��socket�汾
		*/
		bool CLSocket::bindSocketVersion();
	#elif __linux__
	int clSocket;
	#elif __APPLE__

	#endif

};

#endif