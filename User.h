#pragma once
#include<list>
#include "Message.h"
#include "Post.h"
using namespace std;
class USocial;
class User
{
private:
	USocial* _usocial;
	unsigned long _id;
	string _name;
	list<unsigned long> _friends;
	list<Post*> _posts;
	list<Message*> _recievedMessages;
	bool friendExists(User* user);
public:
	User();
	User(string name);
	User(string name, USocial* usocial, unsigned long id);
	~User();
	unsigned long getId();
	string getName();
	void addFriend(User* user);
	void removeFriend(User* user);
	void post(string str);
	void post(string str, Media* media);
	list<Post*> getPosts();
	void viewFriendsPosts();
	void recieveMessage(Message* message);
	void sendMessage(User* user, Message* message);
	void viewReceivedMessages();
};

