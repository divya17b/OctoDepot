#include <string>
#include <iostream>
#include <sqlite3.h>
#include "Menu.hpp"
#include "AdminMenu.hpp"
#include "../../Domain/UserHandler/UserHandler.hpp"
#include "../../TechnicalServices/DatabaseConnector/DatabaseConnector.hpp"

AdminMenu::AdminMenu(int userid) {
    session_userid = userid;
}

void AdminMenu::initSelections() {
    menu = "Admin menu\n-------------------\n1. Modify Customer Information\n0. Logout";
}
void AdminMenu::takeSelection() {
    int selection = -1;
    std::cout << "\n: ";
    std::cin >> selection;

    // print selection, debug purpose
    // std::cout << selection << std::endl;

    switch (selection) {
        case 0:
            this->logout();
            break;
        case 1: {
            UserHandler userHandler(session_userid);
            std::string company_name, contact_name, address, email, phone;
            int userid;
            userid       = this->requestNumeric("User Modification | Please Give a User ID : ");
            company_name = this->requestString("Company Name: ");
            contact_name = this->requestString("Contact Name: ");
            address      = this->requestString("Address: ");
            email        = this->requestString("Email: ");
            phone        = this->requestString("Phone: ");
            userid = userHandler.modifyUser(userid, company_name, contact_name, address, email, phone);

            std::cout << "User " << userid << "'s information is modified by Admin-" << session_userid << std::endl;
            break;
        }
        default:
            break;
    }
}

void AdminMenu::sessionLoop() {
    this->initSelections();
    this->clearScreen();
    while (isActive) {
        this->displayMenu();
        this->takeSelection();
    }
}