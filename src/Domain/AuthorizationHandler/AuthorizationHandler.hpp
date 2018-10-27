#ifndef AuthorizationHandler_HPP
#define AuthorizationHandler_HPP

class AuthorizationHandler {
public:
    AuthorizationHandler();
    int authenticate(int userid, std::string password);
};

#endif