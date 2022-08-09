#include "HttpResponse.h"

HttpResponse::HttpResponse()
{
	header.insert(std::map<std::string, std::string>::value_type("Connection", "keep-alive"));
	header.insert(std::map<std::string, std::string>::value_type("Content-Type", "text/html"));
}

HttpResponse::~HttpResponse()
{

}

std::string HttpResponse::toString() {
	std::string data = "";

	//http版本
	data.append(Http::HttpVersionTostr(version,&error));
	if (error != "") {
		return data;
	}
	data.append(" ");

	//状态码
	data.append(std::to_string(state));
	data.append(" ");

	//状态信息
	data.append(stateMsg);
	data.append("\r\n");

	//响应头
	std::map<std::string, std::string>::iterator iter;
	header.insert(std::map<std::string, std::string>::value_type("Content-Length", std::to_string(body.size())));
	for (iter = header.begin(); iter != header.end(); iter++) {
		data.append(iter->first).append(": ").append(iter->second).append("\r\n");
	}
	data.append("\r\n");

	//内容
	data.append(body);

	return data;
}

std::string HttpResponse::to404()
{
	HttpResponse h;
	h.state = 404;
	h.body = "找不到网页";
	return h.toString();
}

std::string HttpResponse::toError(int state, ResponseMessage * responseMessage)
{
	HttpResponse h;
	h.state = state;
	h.body = responseMessage->toString();
	return h.toString();
}

std::string HttpResponse::toError(ResponseMessage * responseMessage)
{
	return toError(400, responseMessage);
}
