#ifndef AuthorizationHandler_HPP
#define AuthorizationHandler_HPP

#include "../EventHandler/EventHandler.hpp"

// expanding EventHandler, adding authenticatie method
class AuthorizationHandler : public EventHandler {
public:
    AuthorizationHandler();
    // authenticate userid/password combination
    int authenticate(int userid, std::string password);
};

#endif