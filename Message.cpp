#pragma once
#include "Message.h"
Message::Message(std::string str) {
	text = str;
}
std::string Message::getText() {
	return this->text;
}
Message::~Message() {
}


