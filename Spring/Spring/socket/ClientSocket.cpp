#include "ClientSocket.h"

ClientSocket::ClientSocket()
{

}

ClientSocket::~ClientSocket()
{
	clientRunThread->detach();
	delete clientRunThread;
}



/*
	�رռ̳�
*/
void ClientSocket::CloseSocket() {

}


//
void ClientSocket::run() {
	clientRunThread = new std::thread([=]() {
		while (!isClose)
		{

			try
			{
				std::string data = readSocket();
				if ("" != error) {
					close();
					break;
				}

				/*
					��ȡ�����麯��
				*/
				readData(&data, &error);
				if ("" != error) {
					close();
					break;
				}
			}
			catch (const std::exception& e)
			{
				std::cout << "�쳣����" << std::endl;
			}
		}});
}
