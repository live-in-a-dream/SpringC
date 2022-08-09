#include "CLSocket.h"

CLSocket::CLSocket()
{

}

CLSocket::~CLSocket()
{
	close();

	closesocket(clSocket);

	std::cout << "CLSocket������" << std::endl;
}

/*
	�������Ͷ˿�
*/
bool CLSocket::bindSocket(Address* address) {
	SOCKADDR_IN ServerAddr;

	ServerAddr.sin_family = domain;

	ServerAddr.sin_addr.S_un.S_addr = inet_addr(address->ip);

	ServerAddr.sin_port = htons(address->port);
	//�������Ͷ˿�
	int retVal = bind(clSocket, (SOCKADDR *)&ServerAddr, sizeof(SOCKADDR_IN));
	if (retVal == SOCKET_ERROR) {
		error = "�󶨶˿�ʧ��";
		return false;
	}
	std::cout << "�󶨶˿ڳɹ�" << std::endl;
	return true;
}

//windows
#ifdef _WIN32
/*
 ��socket�汾
*/
bool CLSocket::bindSocketVersion() {
	WORD socketVersion = MAKEWORD(2, 2);
	WSADATA wsd;
	if (WSAStartup(socketVersion, &wsd) != 0)
	{
		error = "�󶨰汾ʧ��";
		return false;
	}
	std::cout << "�󶨰汾�ɹ�" << std::endl;
	return true;
}

//------------------------------------------------------------------------------------
//����
bool CLSocket::sendSocket(const char * data, int len) {
	//�Ѿ������ܳ������
	int length = 0;
	while (!isClose)
	{
		int retVal = send(clSocket, data, len, 0);
		if (retVal == SOCKET_ERROR) {
			error = "����ʧ��,Socket����ر���";
			return false;
		}
		else if (retVal == 0) {
			error.append("�ͻ��˹ر�:").append(address.ip).append(":").append(std::to_string(address.port));
			return false;
		}

		length += retVal;

		//�����ܳ��Ⱥ��Ѿ������ܳ������=���ͳɹ�
		if (length == len) {
			return true;
		}
	}
}

//����
bool CLSocket::sendSocket(const char * data) {
	return sendSocket(data, strlen(data));
}

//��ȡ
std::string CLSocket::readSocket() {
	std::string data;
	while (!isClose)
	{
		//��һλ\0�����ַ�
		char buff[1025] = "\0";
		int retVal = recv(clSocket, buff, 1024, 0);
		if (retVal == SOCKET_ERROR) {
			error = "����ʧ��,Socket����ر���";
			return data;
		}
		else if (retVal == 0) {
			error.append("�ͻ��˹ر�:").append(address.ip).append(":").append(std::to_string(address.port));
			return data;
		}
		//��������������
		else if (retVal == 1024) {
			data.append(buff);
			continue;
		}
		//������û��������
		else if (retVal < 1024) {
			data.append(buff);
			return data;
		}
	}
	return "";
}

//�ر�
void CLSocket::close() {
	if (!isClose) {
		isClose = true;

		//��������
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
