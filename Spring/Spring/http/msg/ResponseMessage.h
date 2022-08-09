#pragma once
#include <iostream>
#include <sstream>

class ResponseMessage
{
public:
	ResponseMessage();
	virtual ~ResponseMessage();


	virtual std::string toString() { return ""; };

private:

};

