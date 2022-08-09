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


	//状态代码
	int code = 200;

	//信息
	std::string msg = "";

	//时间
	std::string date = "";

	//网址
	std::string url = "";

	virtual std::string toString() override;
private:

};

