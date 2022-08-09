#include "DefaultResponseMessage.h"

DefaultResponseMessage::DefaultResponseMessage()
{
}

DefaultResponseMessage::~DefaultResponseMessage()
{
}

std::string DefaultResponseMessage::toString()
{
	rapidjson::StringBuffer s;
	rapidjson::Writer<rapidjson::StringBuffer> writer(s);

	writer.StartObject();
	writer.Key("code");          
	writer.Int(code);       

	writer.Key("msg");
	writer.String(msg.c_str());

	writer.Key("date");
	writer.String(date.c_str());

	writer.Key("url");
	writer.String(url.c_str());

	return s.GetString();
}
