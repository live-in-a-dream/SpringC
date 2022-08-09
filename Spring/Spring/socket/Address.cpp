#include "Address.h"


Address::Address(char* ip, int port) {
	this->ip = ip;
	this->port = port;
}
Address::Address(int port) {
	this->port = port;
}

Address::~Address() {

}