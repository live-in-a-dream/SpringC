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
	关闭继承
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
					读取数据虚函数
				*/
				readData(&data, &error);
				if ("" != error) {
					close();
					break;
				}
			}
			catch (const std::exception& e)
			{
				std::cout << "异常报错" << std::endl;
			}
		}});
}
