#include <string>

#include "AuthorizationHandler.hpp"
#include "../../TechnicalServices/AuthorizationVendorConnector/AuthorizationVendorConnector.hpp"

AuthorizationHandler::AuthorizationHandler() {}

int AuthorizationHandler::authenticate(int userid, std::string password) {
    AuthorizationVendorConnector auth("auth.vendor.com/api/v15/");
    return auth.authenticateUser(userid, password);
}