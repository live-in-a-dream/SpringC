#include "CLSocket.h"

CLSocket::CLSocket()
{

}

CLSocket::~CLSocket()
{
	close();

	closesocket(clSocket);

	std::cout << "CLSocket销毁了" << std::endl;
}

/*
	绑定网卡和端口
*/
bool CLSocket::bindSocket(Address* address) {
	SOCKADDR_IN ServerAddr;

	ServerAddr.sin_family = domain;

	ServerAddr.sin_addr.S_un.S_addr = inet_addr(address->ip);

	ServerAddr.sin_port = htons(address->port);
	//绑定网卡和端口
	int retVal = bind(clSocket, (SOCKADDR *)&ServerAddr, sizeof(SOCKADDR_IN));
	if (retVal == SOCKET_ERROR) {
		error = "绑定端口失败";
		return false;
	}
	std::cout << "绑定端口成功" << std::endl;
	return true;
}

//windows
#ifdef _WIN32
/*
 绑定socket版本
*/
bool CLSocket::bindSocketVersion() {
	WORD socketVersion = MAKEWORD(2, 2);
	WSADATA wsd;
	if (WSAStartup(socketVersion, &wsd) != 0)
	{
		error = "绑定版本失败";
		return false;
	}
	std::cout << "绑定版本成功" << std::endl;
	return true;
}

//------------------------------------------------------------------------------------
//发送
bool CLSocket::sendSocket(const char * data, int len) {
	//已经发送总长度相等
	int length = 0;
	while (!isClose)
	{
		int retVal = send(clSocket, data, len, 0);
		if (retVal == SOCKET_ERROR) {
			error = "发送失败,Socket服务关闭了";
			return false;
		}
		else if (retVal == 0) {
			error.append("客户端关闭:").append(address.ip).append(":").append(std::to_string(address.port));
			return false;
		}

		length += retVal;

		//发送总长度和已经发送总长度相等=发送成功
		if (length == len) {
			return true;
		}
	}
}

//发送
bool CLSocket::sendSocket(const char * data) {
	return sendSocket(data, strlen(data));
}

//读取
std::string CLSocket::readSocket() {
	std::string data;
	while (!isClose)
	{
		//多一位\0结束字符
		char buff[1025] = "\0";
		int retVal = recv(clSocket, buff, 1024, 0);
		if (retVal == SOCKET_ERROR) {
			error = "接受失败,Socket服务关闭了";
			return data;
		}
		else if (retVal == 0) {
			error.append("客户端关闭:").append(address.ip).append(":").append(std::to_string(address.port));
			return data;
		}
		//缓存区还有数据
		else if (retVal == 1024) {
			data.append(buff);
			continue;
		}
		//缓存区没有数据了
		else if (retVal < 1024) {
			data.append(buff);
			return data;
		}
	}
	return "";
}

//关闭
void CLSocket::close() {
	if (!isClose) {
		isClose = true;

		//生命周期
		CloseSocket();

		delete this;
	}
}
#elif __linux__
//
void CLSocket::close() {
	if (!isClose) {
		isClose = true;

		CloseSocket();

		close(clSocket);
		delete this;
	}
}
#elif __APPLE__

#endif
