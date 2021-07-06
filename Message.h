#pragma once
#include <iostream>
class Message
{
private:
	std::string text;
public:
	Message(std::string str);
	~Message();
	std::string getText();
};

