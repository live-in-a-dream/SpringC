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
//地址系列
enum CLSocketDomain
{
	//AF_LOCAL本地通信
	UNIX = AF_UNIX,
	//IPv4网络通信
	INET = AF_INET,
	//IPv6网络通信
	INET6 = AF_INET6,
};

//套接字类型
enum CLSocketType
{
	//A流套接字, 提供顺序，可靠，双向，基于连接的字节流。 可以支持带外数据传输机制。例如：TCP协议、FTP协议
	STREAM = SOCK_STREAM,
	//数据包套接字, 支持数据报（无连接，不可靠的固定最大长度的消息）例如：UDP协议
	DGRAM = SOCK_DGRAM,
	//原始套接字, 使用原始套接字时候调用，原始套接字也就是链路层协议
	RAW = SOCK_RAW,
	//有序分组套接字,为固定最大长度的数据报提供有序，可靠，双向连接的数据传输路径; 消费者需要利用每个输入系统调用读取整个分组
	SEQPACKET = SOCK_SEQPACKET,
};

//协议号
enum CLSocketProtocol
{
	//TCP协议
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

	//地址
	Address address = Address("0.0.0.0", 8999);
	//地址系列
	CLSocketDomain domain = CLSocketDomain::INET;
	//套接字类型
	CLSocketType type = CLSocketType::STREAM;
	//协议号
	CLSocketProtocol protocol = CLSocketProtocol::TCP;


	//错误
	std::string error = "";

	//是否关闭
	bool isClose = false;

public:

	/*
		绑定网卡和端口
	*/
	bool bindSocket(Address* address);

	/*
		发送消息
	*/
	bool sendSocket(const char * data,int len);

	/*
		发送消息
	*/
	bool sendSocket(const char * data);

	/*
		读取消息
	*/
	std::string CLSocket::readSocket();

	/*
		关闭
	*/
	void close();

/*
	生命周期
*/
public:
	virtual void CloseSocket() {};


public:
	#ifdef _WIN32
		SOCKET clSocket;
		/*
		 绑定socket版本
		*/
		bool CLSocket::bindSocketVersion();
	#elif __linux__
	int clSocket;
	#elif __APPLE__

	#endif

};

#endif