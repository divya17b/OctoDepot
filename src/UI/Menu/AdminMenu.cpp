#include <string>
#include <iostream>
#include <sqlite3.h>
#include <bits/unique_ptr.h>
#include "Menu.hpp"
#include "AdminMenu.hpp"
#include "../../Domain/UserHandler/UserHandler.hpp"
#include "../../TechnicalServices/DatabaseConnector/DatabaseConnector.hpp"

AdminMenu::AdminMenu(int userid, bool *continueStatus) {
    session_userid = userid;
    this->parentContinueStatus = continueStatus;
}

AdminMenu::~AdminMenu() {
    delete this->parentContinueStatus;
}

void AdminMenu::initSelections() {
    menu = "Admin menu\n-------------------\n1. Modify Customer Information\n2. Shutdown\n0. Logout";
}
void AdminMenu::takeSelection() {
    int selection = -1;
    std::cout << "\n: ";
    std::cin >> selection;

    switch (selection) {
        case 0:
            this->logout();
            break;
        case 1: {
            std::cout << std::endl << "*** Modify Customer Information ***" << std::endl << std::endl;
            // UserHandler userHandler(session_userid);
            std::unique_ptr<UserHandler> userHandler(new UserHandler(session_userid));
            std::string company_name, contact_name, address, email, phone;
            int userid;
            userid       = this->requestNumeric("User Modification | Please Give a User ID : ");
            company_name = this->requestString("Company Name: ");
            contact_name = this->requestString("Contact Name: ");
            address      = this->requestString("Address: ");
            email        = this->requestString("Email: ");
            phone        = this->requestString("Phone: ");
            userid = userHandler->modifyUser(userid, company_name, contact_name, address, email, phone);

            std::cout << "User " << userid << "'s information is modified by Admin-" << session_userid << std::endl;

            this->pausePrompt();
            break;
        } case 2: {
            // exit(0);
            this->isActive = false;
            *this->parentContinueStatus = false;
        }
        default:
            break;
    }
}