#ifndef AuthorizationHandler_HPP
#define AuthorizationHandler_HPP

#include "../EventHandler/EventHandler.hpp"

class AuthorizationHandler : public EventHandler {
public:
    AuthorizationHandler();
    int authenticate(int userid, std::string password);
};

#endif