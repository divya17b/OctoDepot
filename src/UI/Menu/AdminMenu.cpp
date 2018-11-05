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

// init contents of the Admin Menu
void AdminMenu::initSelections() {
    menu = "Admin menu\n-------------------\n1. Modify Customer Information\n2. Shutdown\n0. Logout";
}
// expanding Menu::takeSelection
void AdminMenu::takeSelection() {
    int selection = -1;
    std::cout << "\n: ";
    std::cin >> selection;

    switch (selection) {
        // option 0 to log out
        case 0:
            this->logout();
            break;
        // option 1 to Modify Customer Information
        // 1. asking the information about the customer
        // 2. create UserHandler object to actuate the modification
        case 1: {
            std::cout << std::endl << "*** Modify Customer Information ***" << std::endl << std::endl;
            // UserHandler userHandler(session_userid);

            // createing new UserHandler object
            std::unique_ptr<UserHandler> userHandler(new UserHandler(session_userid));

            // asking information about user
            std::string company_name, contact_name, address, email, phone;
            int userid;
            userid       = this->requestNumeric("User Modification | Please Give a User ID : ");
            company_name = this->requestString("Company Name: ");
            contact_name = this->requestString("Contact Name: ");
            address      = this->requestString("Address: ");
            email        = this->requestString("Email: ");
            phone        = this->requestString("Phone: ");
            // call modifyUser method of userHandler to actuate the modification
            // catch the user id whose information is modified
            userid = userHandler->modifyUser(userid, company_name, contact_name, address, email, phone);

            std::cout << "User " << userid << "'s information is modified by Admin-" << session_userid << std::endl;

            this->pausePrompt();
            break;
        // option 2 to shut down the system
        } case 2: {
            // exit(0);
            this->isActive = false;
            *this->parentContinueStatus = false;
        }
        default:
            break;
    }
}