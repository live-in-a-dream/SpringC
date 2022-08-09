#include "ServerSocket.h"

ServerSocket::ServerSocket()
{

}


ServerSocket::~ServerSocket()
{

}

//
bool ServerSocket::lister(int backlog) {
	#ifdef _WIN32
		bool isBindSocket = bindSocketVersion();
		//绑定失败
		if (!isBindSocket) {
			return false;
		}
	#elif __linux__

	#elif __APPLE__

	#endif

	//创建socket
	clSocket = socket(domain, type, protocol);

	//绑定
	bool isBindAddress = bindSocket(&address);
	//绑定失败
	if ("" != error) {
		close();
		return false;
	}


	#ifdef _WIN32
		//设置接受数据的超时时间
		if (setsockopt(clSocket, SOL_SOCKET, SO_RCVTIMEO, (char *)&readTime, sizeof(readTime)) == SOCKET_ERROR) {
			error = "设置读取数据超时时间失败";
			close();
			return false;
		}

		//设置发送数据超时时间失败
		if (setsockopt(clSocket, SOL_SOCKET, SO_RCVTIMEO, (char *)&sendTime, sizeof(sendTime)) == SOCKET_ERROR) {
			error = "设置发送数据超时时间失败";
			close();
			return false;
		}
	#elif __linux__

	#elif __APPLE__

	#endif
	

	//开启监听
	int retVal = listen(clSocket, backlog);
	if (retVal == SOCKET_ERROR) {
		error = "监听失败";
		close();
		return false;
	}
	std::cout << "监听成功:" << address.ip << ":" << address.port << std::endl;
	return true;
}

#ifdef _WIN32
//
void ServerSocket::acceptSocket(CLSocket* clientCLSocket) {

	SOCKADDR_IN ClientAddr;
	int ClientAddrLen = sizeof(ClientAddr);
	SOCKET clientSocket = accept(clSocket, (SOCKADDR*)&ClientAddr, &ClientAddrLen);

	Address address(inet_ntoa(ClientAddr.sin_addr), htons(ClientAddr.sin_port));
	clientCLSocket->address = address;
	clientCLSocket->clSocket = clientSocket;

	std::cout << "客户端连接成功:" << address.ip << ":" << address.port << std::endl;
}


#elif __linux__
//
void ServerSocket::acceptSocket(CLSocket* clientCLSocket) {

}
#elif __APPLE__

#endif




