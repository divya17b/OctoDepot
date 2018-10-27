#include <string>
#include <iostream>
#include "../../TechnicalServices/AuthorizationVendorConnector/AuthorizationVendorConnector.hpp"
#include "TextUserInterface.hpp"

TextUserInterface::TextUserInterface() {
    permission = -1;
    current_userid = 0;
    isActive = true;
    std::cout << "ta-da!" << std::endl;
    this->MainLoop();
}

// bool TextUserInterface::isActive() {
//     return running;
// }

// int TextUserInterface::getPermission() {
//     return permission;
// }

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
    AuthorizationVendorConnector auth("auth.vendor.com/api/v15/");

    // ask userid and password
    int userid = 0;
    std::string password = "";
    userid = this->askUserID();
    password = this->askUserPassword();

    // // for debug only
    // std::cout << userid << "/" << password << std::endl;

    // get permission from Auth Vendor
    permission = auth.authenticateUser(userid, password);
    if (permission == -1) {
        std::cout << "Incorrect login credential." << std::endl;
    }
}

void TextUserInterface::startSession() {
    if (permission == 0) {
        // start admin session here
        std::cout << "Starting Admin Session..." << std::endl;
    } else if (permission == 100) {
        // start manager session here
        std::cout << "Starting Manager Session..." << std::endl;
    } else if (permission == 200) {
        // start auditor session here
        std::cout << "Starting Auditor Session..." << std::endl;
    } else if (permission == 1000) {
        // start customer session here
        std::cout << "Starting Customer Session..." << std::endl;
    } else {
        // incorrect permission should not start anything
        // but send out another login
        // put here for foolproof purpose
    }
    permission = -1;
}
void TextUserInterface::shutdown() {
    isActive = false;
}

void TextUserInterface::MainLoop() {
    while (isActive) {
        if (permission == -1) {
            this->login();
        } else {
            this->startSession();
        }
    }
}