#include <string>
#include <vector>
#include <fstream>
#include <sqlite3.h>
#include <bits/unique_ptr.h>

#include "../EventHandler/EventHandler.hpp"
#include "UserHandler.hpp"
#include "../../TechnicalServices/DatabaseConnector/DatabaseConnector.hpp"
#include "../../TechnicalServices/Logger/Logger.hpp"

#include <stdlib.h>
#include <time.h>

UserHandler::UserHandler(int userid) {
    session_userid = userid;
}

// create new user and call DatabaseConnector to persist user into DB
int UserHandler::createUser(std::string company_name, std::string contact_name, std::string address, std::string email,std::string phone) {
    int userid = -1;
    srand(time(NULL));
    userid = rand() % 999999 + 100001;

    // create DatabaseConnector object and call usercreate method to persist information about user into the database
    std::unique_ptr<DatabaseConnector> db(new DatabaseConnector("test.db"));
    db->UserCreate(userid, company_name, contact_name, address, email, phone);

    // log this activity
    // Logger *logger = new Logger("test.log");
    // Logger logger("test.log");
    std::unique_ptr<Logger> logger(new Logger("test.log"));
    std::string msg = "User " + std::to_string(userid) + " created by " + std::to_string(session_userid);
    logger->log("USER", session_userid, msg);

    // return the user id created
    return userid;
}

// find existing user and modify that user's information is db
int UserHandler::modifyUser(int userid, std::string company_name, std::string contact_name, std::string address, std::string email,std::string phone) {
    // create DatabaseConnector object and modify information about perticular user in the db
    std::unique_ptr<DatabaseConnector> db(new DatabaseConnector("test.db"));
    int status = db->UserModify(userid, company_name, contact_name, address, email, phone);

    // log this activity
    // Logger *logger = new Logger("test.log");
    // Logger logger("test.log");
    std::unique_ptr<Logger> logger(new Logger("test.log"));
    std::string msg = "User " + std::to_string(userid) + " modified by " + std::to_string(session_userid);
    logger->log("USER", session_userid, msg);

    return status;
}