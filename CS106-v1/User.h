#ifndef USER_H
#define USER_H

#include <string>
#include "Usertype.h"

class User {
    std::string username;
    std::string password;
    Usertype userType;
public:
    User() : username(""), password(""), userType(Usertype::Developer) {}
    User(const std::string& username, const std::string& password, Usertype userType);

    std::string getUsername() const { return username; }
    std::string getPassword() const { return password; }
    Usertype getUserType() const { return userType; }
};

#endif // USER_H
