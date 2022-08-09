#include "Http.h"

Http::Http()
{

}

Http::~Http()
{

}

//
Http::CLHttpMethod Http::strToCLHttpMethod(std::string str, std::string* error) {
	if ("GET" == str) {
		return Http::CLHttpMethod::GET;
	}
	else if ("POST" == str) {
		return Http::CLHttpMethod::POST;
	}
	else if ("HEAD" == str) {
		return Http::CLHttpMethod::HEAD;
	}
	else if ("PUT" == str) {
		return Http::CLHttpMethod::PUT;
	}
	else {
		error->append("http不支持" + str + "此方法");
	}
	return Http::CLHttpMethod::METHOD_NONE;
}


//
Http::CLHttpVersion Http::strToHttpVersion(std::string str, std::string* error) {
	if ("HTTP/1.0" == str) {
		return Http::CLHttpVersion::HTTP1_0;
	}
	else if ("HTTP/1.1" == str) {
		return Http::CLHttpVersion::HTTP1_1;
	}
	else {
		error->append(str + "版本不正确");
	}
	return Http::CLHttpVersion::VERSION_NONE;
}

//
std::string Http::HttpVersionTostr(Http::CLHttpVersion version, std::string* error) {
	if (Http::CLHttpVersion::HTTP1_0 == version) {
		return "HTTP/1.0";
	}
	else if (Http::CLHttpVersion::HTTP1_1 == version) {
		return "HTTP/1.1";
	}
	else {
		error->append("转换版本不正确");
	}
	return "";
}

//
void Http::strToQueryParam(std::map<std::string, std::string>* queryParam,std::string* url, std::string* error) {
	std::vector<std::string> param = StringUtils::split(url, "?");
	
	if (2 == param.size()) {
		url = &param.at(0);
		std::string p = param.at(1);
		std::vector<std::string> keyValues = StringUtils::split(&p, "&");

		for (int i = 0; i < keyValues.size(); i++) {
			std::vector<std::string> keyValue = StringUtils::split(&keyValues.at(i), "=");
			std::string value = "";
			std::string pr = keyValue.at(0);
			if (2 == keyValue.size()) {
				value = keyValue.at(1);
			}
			queryParam->insert(std::map<std::string, std::string>::value_type(pr, value));
		}
	}
	else if (1 == param.size()){
		url = &param.at(0);
	}
	else {
		error->append("网址请求错误");
	}
}