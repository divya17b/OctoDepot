#include <string>
#include <iostream>
#include <sqlite3.h>
#include <bits/unique_ptr.h>
#include "Menu.hpp"
#include "SalespersonMenu.hpp"
#include "../../Domain/UserHandler/UserHandler.hpp"
#include "../../TechnicalServices/DatabaseConnector/DatabaseConnector.hpp"

SalespersonMenu::SalespersonMenu(int userid) {
    session_userid = userid;
}

SalespersonMenu::~SalespersonMenu() {}

void SalespersonMenu::initSelections() {
    menu = "Salesperson menu\n-------------------\n1. Create New Customer Account\n0. Logout";
}
void SalespersonMenu::takeSelection() {
    int selection = -1;
    selection = this->requestNumeric("\n: ");

    switch (selection) {
        case 0:
            this->logout();
            break;
        case 1: {
            std::cout << std::endl << "*** Create New Customer ***" << std::endl << std::endl;
            std::unique_ptr<UserHandler> userHandler(new UserHandler(session_userid));
            std::string company_name, contact_name, address, email, phone;
            company_name = this->requestString("Company Name: ");
            contact_name = this->requestString("Contact Name: ");
            address      = this->requestString("Address: ");
            email        = this->requestString("Email: ");
            phone        = this->requestString("Phone: ");
            int userid = userHandler->createUser(company_name, contact_name, address, email, phone);

            std::cout << "User created with ID -> " << userid << " By Sales Manager ID-" << session_userid << std::endl;
            
            this->pausePrompt();
            break;
        }
        default:
            break;
    }
}