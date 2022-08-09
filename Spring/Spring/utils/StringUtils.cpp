#include "StringUtils.h"


StringUtils::StringUtils()
{
}

StringUtils::~StringUtils()
{
}

//·Ö¸î
std::vector<std::string> StringUtils::split(std::string* data, const char * separator) {
	std::vector<std::string> list;

	int number = 0;

	size_t oldPos = 0;
	while (true)
	{
		size_t pos = data->find(separator, oldPos);
		//ÕÒ²»µ½
		if (pos == data->npos) {
			std::string p = data->substr(oldPos, data->size());
			list.push_back(p);
			return list;
		}
		std::string p = data->substr(oldPos, pos-oldPos);

		oldPos = pos + strlen(separator);

		list.push_back(p);
	}
}