#pragma once
#include "User.h"
class BusinessUser :
    public User
{
public:
    void sendMessage(User* user, Message* message);
    BusinessUser(string name, USocial* usocial, unsigned long id);
};

