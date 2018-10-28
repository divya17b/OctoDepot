#ifndef LOGHANDLER_HPP
#define LOGHANDLER_HPP

class UserHandler {
public:
    UserHandler();
    int createUser(std::string company_name, std::string contact_name, std::string address, std::string email,std::string phone);
};

#endif