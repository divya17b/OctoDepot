#ifndef LOGHANDLER_HPP
#define LOGHANDLER_HPP

#include "../EventHandler/EventHandler.hpp"

class UserHandler : public EventHandler {

public:
    UserHandler(int userid);
    int createUser(std::string company_name, std::string contact_name, std::string address, std::string email,std::string phone);
    int modifyUser(int userid, std::string company_name, std::string contact_name, std::string address, std::string email,std::string phone);
};

#endif