#include <string>
#include <fstream>
#include <vector>
#include <bits/unique_ptr.h>

#include "AuthorizationHandler.hpp"
#include "../../TechnicalServices/AuthorizationVendorConnector/AuthorizationVendorConnector.hpp"
#include "../../TechnicalServices/Logger/Logger.hpp"

AuthorizationHandler::AuthorizationHandler() {}

// authenticate userid/password combination
int AuthorizationHandler::authenticate(int userid, std::string password) {
    // create AuthorizationVendorConnector object
    std::unique_ptr<AuthorizationVendorConnector> auth(new AuthorizationVendorConnector("auth.vendor.com/api/v15/"));
    // call authenticateUser to verify userid/password
    int userid_logged_in = auth->authenticateUser(userid, password);

    // create logger object and log the login event
    std::unique_ptr<Logger> logger(new Logger("test.log"));
    std::string msg;
    msg = "User - " + std::to_string(userid_logged_in) + " logged in.";
    logger->log("LOGIN", userid_logged_in, msg);
    return userid_logged_in;
}