#include <string>
#include <iostream>
#include <sqlite3.h>
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

    // print selection, debug purpose
    // std::cout << selection << std::endl;

    switch (selection) {
        case 0:
            this->logout();
            break;
        case 1: {
            std::cout << std::endl << "*** Create New Customer ***" << std::endl << std::endl;
            UserHandler userHandler(session_userid);
            std::string company_name, contact_name, address, email, phone;
            company_name = this->requestString("Company Name: ");
            contact_name = this->requestString("Contact Name: ");
            address      = this->requestString("Address: ");
            email        = this->requestString("Email: ");
            phone        = this->requestString("Phone: ");
            int userid = userHandler.createUser(company_name, contact_name, address, email, phone);

            std::cout << "User created with ID -> " << userid << " By Sales Manager ID-" << session_userid << std::endl;
            
            this->pausePrompt();
            break;
        }
        default:
            break;
    }
}

// int SalespersonMenu::requestNumeric(std::string prompt) {
//     int result;
//     std::cout << prompt;
//     std::cin >> result;
//     std::cin.ignore();
//     return result;
// }
// std::string SalespersonMenu::requestString(std::string prompt) {
//     std::string result;
//     std::cout << prompt;
//     std::getline(std::cin, result);
//     return result;
// }

// void SalespersonMenu::sessionLoop() {
//     this->initSelections();
//     this->clearScreen();
//     while (isActive) {
//         this->displayMenu();
//         this->takeSelection();
//     }
// }