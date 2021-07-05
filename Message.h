#pragma once
#include <iostream>
class Message
{
private:
	std::string text;
public:
	Message(std::string str);
	std::string getText();
};

