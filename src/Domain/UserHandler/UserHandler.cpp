#include <string>
#include <sqlite3.h>
#include "UserHandler.hpp"
#include "../../TechnicalServices/DatabaseConnector/DatabaseConnector.hpp"

#include <stdlib.h>
#include <time.h>

UserHandler::UserHandler() {}

int UserHandler::createUser(std::string company_name, std::string contact_name, std::string address, std::string email,std::string phone) {
    int userid = -1;
    srand(time(NULL));
    userid = rand() % 999999 + 100001;

    DatabaseConnector db("test.db");
    db.UserCreate(userid, company_name, contact_name, address, email, phone);
    return userid;
}

int UserHandler::modifyUser(int userid, std::string company_name, std::string contact_name, std::string address, std::string email,std::string phone) {
    DatabaseConnector db("test.db");
    return db.UserModify(userid, company_name, contact_name, address, email, phone);
}