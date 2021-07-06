#pragma once
#include "BusinessUser.h"
#include<map>
class USocial
{
private:
	map<unsigned long, User*> _users;
	unsigned long _id_counter;
public:
	USocial();
	User* registerUser(std::string name);
	User* registerUser(std::string name, bool boolean);
	User* getUserById(unsigned long id);
	void removeUser(User* user);
	void kill();
};

