#ifndef LOGHANDLER_HPP
#define LOGHANDLER_HPP

#include "../EventHandler/EventHandler.hpp"

// Expand EventHandler, add create and modify user
class UserHandler : public EventHandler {

public:
    UserHandler(int userid);
    // create new user and call DatabaseConnector to persist user into DB
    int createUser(std::string company_name, std::string contact_name, std::string address, std::string email,std::string phone);
    // find existing user and modify that user's information is db
    int modifyUser(int userid, std::string company_name, std::string contact_name, std::string address, std::string email,std::string phone);
};

#endif