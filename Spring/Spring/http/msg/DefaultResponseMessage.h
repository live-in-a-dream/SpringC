#pragma once
#include "ResponseMessage.h"
#include "../rapidjson/document.h"
#include "../rapidjson/stringbuffer.h"
#include "../rapidjson/writer.h"

class DefaultResponseMessage : public ResponseMessage
{
public:
	DefaultResponseMessage();
	virtual ~DefaultResponseMessage();


	//״̬����
	int code = 200;

	//��Ϣ
	std::string msg = "";

	//ʱ��
	std::string date = "";

	//��ַ
	std::string url = "";

	virtual std::string toString() override;
private:

};

