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
		//��ʧ��
		if (!isBindSocket) {
			return false;
		}
	#elif __linux__

	#elif __APPLE__

	#endif

	//����socket
	clSocket = socket(domain, type, protocol);

	//��
	bool isBindAddress = bindSocket(&address);
	//��ʧ��
	if ("" != error) {
		close();
		return false;
	}


	#ifdef _WIN32
		//���ý������ݵĳ�ʱʱ��
		if (setsockopt(clSocket, SOL_SOCKET, SO_RCVTIMEO, (char *)&readTime, sizeof(readTime)) == SOCKET_ERROR) {
			error = "���ö�ȡ���ݳ�ʱʱ��ʧ��";
			close();
			return false;
		}

		//���÷������ݳ�ʱʱ��ʧ��
		if (setsockopt(clSocket, SOL_SOCKET, SO_RCVTIMEO, (char *)&sendTime, sizeof(sendTime)) == SOCKET_ERROR) {
			error = "���÷������ݳ�ʱʱ��ʧ��";
			close();
			return false;
		}
	#elif __linux__

	#elif __APPLE__

	#endif
	

	//��������
	int retVal = listen(clSocket, backlog);
	if (retVal == SOCKET_ERROR) {
		error = "����ʧ��";
		close();
		return false;
	}
	std::cout << "�����ɹ�:" << address.ip << ":" << address.port << std::endl;
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

	std::cout << "�ͻ������ӳɹ�:" << address.ip << ":" << address.port << std::endl;
}


#elif __linux__
//
void ServerSocket::acceptSocket(CLSocket* clientCLSocket) {

}
#elif __APPLE__

#endif




