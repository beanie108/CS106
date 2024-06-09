#include "User.h"

User::User(const std::string& username, const std::string& password, Usertype userType)
    : username(username), password(password), userType(userType) {}
