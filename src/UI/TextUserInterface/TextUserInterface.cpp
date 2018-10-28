#include <string>
#include <iostream>
#include "../../Domain/AuthorizationHandler/AuthorizationHandler.hpp"
#include "../../UI/Menu/Menu.hpp"
#include "../../UI/Menu/AuditorMenu.hpp"
#include "../../UI/Menu/SalespersonMenu.hpp"
#include "../../UI/Menu/AdminMenu.hpp"
#include "../../UI/Menu/CustomerMenu.hpp"
#include "TextUserInterface.hpp"

TextUserInterface::TextUserInterface() {
    permission = -1;
    current_userid = 0;
    isActive = true;
    // strat mainloop
    this->MainLoop();
}

int TextUserInterface::askUserID() {
    int userid = 0;
    std::cout << "login: ";
    std::cin >> userid;
    return userid;
}

std::string TextUserInterface::askUserPassword() {
    std::string password;
    std::cout << "password: ";
    std::cin >> password;
    return password;
}

void TextUserInterface::login() {
    // init AuthVendor connector
    // AuthorizationVendorConnector auth("auth.vendor.com/api/v15/");
    AuthorizationHandler auth;
    // ask userid and password
    int userid = -1;
    std::string password = "";
    userid = this->askUserID();
    password = this->askUserPassword();

    // // for debug only
    // std::cout << userid << "/" << password << std::endl;

    // get permission from Auth Vendor
    permission = auth.authenticate(userid, password);
    if (permission == -1) {
        std::cout << "Incorrect login credential." << std::endl;
    }
}

void TextUserInterface::startSession() {
    if (permission == 0) {
        // start admin session here
        std::cout << "Starting Admin Session..." << std::endl;
        AdminMenu adminMenu;
        adminMenu.sessionLoop();
        // this->shutdown();
    } else if (permission == 100) {
        // start Salesperson session here
        std::cout << "Starting Manager Session..." << std::endl;
        SalespersonMenu salesMenu;
        salesMenu.sessionLoop();
    } else if (permission == 200) {
        // start auditor session here
        std::cout << "Starting Auditor Session..." << std::endl;
        AuditorMenu auditormenu;
        auditormenu.sessionLoop();
    } else if (permission == 1000) {
        // start customer session here
        std::cout << "Starting Customer Session..." << std::endl;
        CustomerMenu customerMenu;
        customerMenu.sessionLoop();
    } else {
        // incorrect permission should not start anything
        // but send out another login
        // put here for foolproof purpose
        std::cout << "User ID or Password Incorrect, try again." << std::endl;
    }
    permission = -1;
}
void TextUserInterface::shutdown() {
    isActive = false;
}

void TextUserInterface::MainLoop() {
    while (isActive) {
        if (permission == -1) {
            this->printLogo();
            this->login();
        } else {
            this->startSession();
        }
    }
    std::cout << "Shutting down...\nBye!" << std::endl;
}

void TextUserInterface::printLogo() {
    std::string logo = "   ____       _        _____                   _   \n  / __ \\     | |      |  __ \\                 | |  \n | |  | | ___| |_ ___ | |  | | ___ _ __   ___ | |_ \n | |  | |/ __| __/ _ \\| |  | |/ _ | '_ \\ / _ \\| __|\n | |__| | (__| || (_) | |__| |  __| |_) | (_) | |_ \n  \\____/ \\___|\\__\\___/|_____/ \\___| .__/ \\___/ \\__|\n                                  | |              \n                                  |_|              \n";
    std::cout << logo << std::endl;
}