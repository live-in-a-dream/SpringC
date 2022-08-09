#pragma once
#include "ClientSocket.h"
#include <mutex>

class HttpClient : public ClientSocket
{
public:
	HttpClient();
	virtual ~HttpClient();

	virtual void readData(std::string* data, std::string* error)override;
private:

};

