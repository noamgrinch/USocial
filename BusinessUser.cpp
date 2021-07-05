#include "BusinessUser.h"
#include"Message.h"
#include "User.h"
BusinessUser::BusinessUser(string name, USocial* usocial, unsigned long id) :
	User(name, usocial, id) {

}

void BusinessUser::sendMessage(User* user, Message* message) {
	user->recieveMessage(message);
}
