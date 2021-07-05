#include "User.h"
#include<iostream>
#include <list>
#include<stdio.h>
#include"USocial.h"
#include "Post.h"
#include "Message.h"
#include <stdexcept>
#include <sstream>
#include <string>
using namespace std;

User::User(string name, USocial* usocial, unsigned long id) {
	_name = name;
	_usocial = usocial;
	_id = id;
}

User::User(string name) {
	_name = name;
}

User::User() {

}
User::~User() {
	delete this;
}
unsigned long User::getId() {
	return _id;
}
string User::getName() {
	return _name;
}
void User::addFriend(User* user) {
	if (!friendExists(user)) {
		std::stringstream message;
		message << "User with id " << user->getId() << " is not your friend.";
		throw std::invalid_argument(message.str());
	}
	_friends.push_back(user->getId());
}
void User::removeFriend(User* user) {
	if (!friendExists(user)) {
		std::stringstream message;
		message << "User with id " << user->getId() << " is not your friend.";
		throw std::invalid_argument(message.str());
	}
	_friends.remove(user->getId());
}
void User::post(string str) {
	_posts.push_back(new Post(str));
}
void User::post(string str, Media* media) {
	_posts.push_back(new Post(str, media));
}

void User::viewFriendsPosts() {
	for (const auto& friendId : _friends) {
		User* friendy = _usocial->getUserById(friendId);
		for (const auto& post : friendy->getPosts())
		{
			std::cout << "Post: " << post->getText();
			if (post->getMedia() != NULL) {
				std::cout << " Media: ";
				post->getMedia()->display();
			}
			std::cout << std::endl;
		}
	}
}
void User::recieveMessage(Message* message) {
	_recievedMessages.push_back(message);
}
void User::sendMessage(User* user, Message* message) {
	if (!friendExists(user)) {
		std::stringstream message;
		message << "User with id " << user->getId() << " is not your friend. Cannot send message.";
		throw std::invalid_argument(message.str());
	}
	user->recieveMessage(message);
}
void User::viewReceivedMessages() {
	for (const auto& message : _recievedMessages) {
		std::cout << "Message: " << message->getText() << std::endl;
	}
}
bool User::friendExists(User* user) {
	for (const auto& friendId : _friends) {
		if (user->getId() == friendId) {
			return true;
		}
	}
	return false;
}

list<Post*> User::getPosts() {
	return _posts;
}
