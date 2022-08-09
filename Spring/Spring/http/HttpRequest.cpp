#include "HttpRequest.h"

HttpRequest::HttpRequest()
{

}

HttpRequest::HttpRequest(std::string* data)
{
	this->data = data;
	analysis(data);
}


void HttpRequest::analysis(std::string* data) {
	//
	std::stringstream sstream(data->c_str());
	std::string buff;
	getline(sstream, buff, '\r');

	//方法 网址  请求头
	std::vector<std::string> versionList = StringUtils::split(&buff, " ");

	if (3 == versionList.size()) {
		std::string method = versionList.at(0);
		this->url = versionList.at(1);
		std::string version = versionList.at(2);

		this->method = Http::strToCLHttpMethod(method, &error);
		if (error != "") {
			return;
		}

		Http::strToQueryParam(&queryParam, &this->url, &error);
		if (error != "") {
			return;
		}

		this->version = Http::strToHttpVersion(version, &error);
		if (error != "") {
			return;
		}
	}
	else {
		error = "不是HTTP请求";
		return;
	}

	//请求头获取
	while (true)
	{
		getline(sstream, buff, '\r');
		buff.replace(0, 1, "");
		if (buff == "") {
			break;
		}

		std::vector<std::string> headerList = StringUtils::split(&buff, ": ");
		if (2 != headerList.size()) {
			error = "请求头格式不正确";
			return;
		}
		header.insert(std::map<std::string, std::string>::value_type(headerList.at(0), headerList.at(1)));

		if (sstream.eof()) {
			break;
		}
	}

	this->host = header.at("Host");

	//内容体
	sstream >> this->body;
}

HttpRequest::~HttpRequest()
{
	std::cout << "HttpResponse销毁了" << std::endl;
}
