#include <string>
#include <fstream>
#include <vector>

#include "AuthorizationHandler.hpp"
#include "../../TechnicalServices/AuthorizationVendorConnector/AuthorizationVendorConnector.hpp"
#include "../../TechnicalServices/Logger/Logger.hpp"

AuthorizationHandler::AuthorizationHandler() {}

int AuthorizationHandler::authenticate(int userid, std::string password) {
    AuthorizationVendorConnector auth("auth.vendor.com/api/v15/");
    int userid_logged_in = auth.authenticateUser(userid, password);

    // create logger object and log the login event
    Logger logger("test.log");
    std::string msg;
    msg = "User - " + std::to_string(userid_logged_in) + " logged in.";
    logger.log("LOGIN", userid_logged_in, msg);
    return userid_logged_in;
}