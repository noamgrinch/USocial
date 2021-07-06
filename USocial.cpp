#include "USocial.h"
#include<map>
#include <stdexcept>
#include <sstream>
#include <string>
using namespace std;
USocial::USocial() {
	_id_counter = 1;
}
USocial::~USocial() {
	map<unsigned long, User*>::iterator it;
	for (it = _users.begin(); it != _users.end(); it++)
	{
		delete it->second;
	}
	_users.clear();
	std::cout << "USocial is destructed." << std::endl;
}
User* USocial::registerUser(string name) {
	User* user = new User(name, this, _id_counter);
	_users.insert({ _id_counter , user });
	_id_counter++;
	return user;
}
User* USocial::registerUser(string name, bool boolean) { // Whats the bool for?
	if (boolean) {
		User* user = new BusinessUser(name, this, _id_counter);
		_users.insert({ _id_counter , user });
		_id_counter++;
		return user;
	}
	return new User(name);
}
void USocial::removeUser(User* user) {
	if (_users.count(user->getId()) == 0) {
		std::stringstream message;
		message << "User with id " << user->getId() << " does not exists.";
		throw std::invalid_argument(message.str());
	}
	_users.erase(user->getId());
}
User* USocial::getUserById(unsigned long id) {
	if (_users.count(id) == 0) {
		std::stringstream message;
		message << "User with id " << id << " does not exists.";
		throw std::invalid_argument(message.str());
	}
	return _users.find(id)->second;
}