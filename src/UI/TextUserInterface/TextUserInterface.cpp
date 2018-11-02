#include <string>
#include <iostream>
#include <unistd.h>
#include <bits/unique_ptr.h>
#include "../../Domain/AuthorizationHandler/AuthorizationHandler.hpp"
#include "../../Domain/OrderHandler/OrderHandler.hpp"
#include "../../Domain/UserHandler/UserHandler.hpp"
#include "../../Domain/LogHandler/LogHandler.hpp"
#include "../../UI/Menu/Menu.hpp"
#include "../../UI/Menu/AuditorMenu.hpp"
#include "../../UI/Menu/SalespersonMenu.hpp"
#include "../../UI/Menu/AdminMenu.hpp"
#include "../../UI/Menu/CustomerMenu.hpp"
#include "TextUserInterface.hpp"

TextUserInterface::TextUserInterface() {
    version = "OctoDepot Virtual Warehouse Version 1.0 Beta";
    permission = -1;
    current_userid = -1;
    isActive = true;
    // strat mainloop
    this->MainLoop();
}

void TextUserInterface::clearScreen() {
    for (int i=0;i<24;i++) std::cout << std::endl;
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
    // int userid = -1;
    std::string password = "";
    current_userid = this->askUserID();
    password = this->askUserPassword();

    // // for debug only
    // std::cout << userid << "/" << password << std::endl;

    // get permission from Auth Vendor
    permission = auth.authenticate(current_userid, password);
    if (permission == -1) {
        std::cout << "Incorrect login credential." << std::endl;
        current_userid = -1;
        sleep(2);
    }
}

void TextUserInterface::startSession() {
    if (permission == 0) {
        // start admin session here
        // isActive is passed to AdminMenu in case of Admin changing the run state of system
        std::unique_ptr<Menu> adminMenu(new AdminMenu(current_userid, &this->isActive));
        adminMenu->sessionLoop();
    } else if (permission == 100) {
        // start Salesperson session here
        std::unique_ptr<Menu> salesMenu(new SalespersonMenu(current_userid));
        salesMenu->sessionLoop();
    } else if (permission == 200) {
        // start auditor session here
        std::unique_ptr<Menu> auditorMenu(new AuditorMenu(current_userid));
        auditorMenu->sessionLoop();
    } else if (permission == 1000) {
        // start customer session here
        std::unique_ptr<Menu> customerMenu(new CustomerMenu(current_userid));
        customerMenu->sessionLoop();
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
    this->printBye();
}

void TextUserInterface::printLogo() {
    this->clearScreen();
    std::string logo = 
" ██████╗  ██████╗████████╗ ██████╗        \n"
"██╔═══██╗██╔════╝╚══██╔══╝██╔═══██╗       \n"
"██║   ██║██║        ██║   ██║   ██║       \n"
"██║   ██║██║        ██║   ██║   ██║       \n"
"╚██████╔╝╚██████╗   ██║   ╚██████╔╝       \n"
" ╚═════╝  ╚═════╝   ╚═╝    ╚═════╝        \n"
"                                          \n"
"██████╗ ███████╗██████╗  ██████╗ ████████╗\n"
"██╔══██╗██╔════╝██╔══██╗██╔═══██╗╚══██╔══╝\n"
"██║  ██║█████╗  ██████╔╝██║   ██║   ██║   \n"
"██║  ██║██╔══╝  ██╔═══╝ ██║   ██║   ██║   \n"
"██████╔╝███████╗██║     ╚██████╔╝   ██║   \n"
"╚═════╝ ╚══════╝╚═╝      ╚═════╝    ╚═╝   \n";

    // std::string logo = "   ____       _        _____                   _   \n  / __ \\     | |      |  __ \\                 | |  \n | |  | | ___| |_ ___ | |  | | ___ _ __   ___ | |_ \n | |  | |/ __| __/ _ \\| |  | |/ _ | '_ \\ / _ \\| __|\n | |__| | (__| || (_) | |__| |  __| |_) | (_) | |_ \n  \\____/ \\___|\\__\\___/|_____/ \\___| .__/ \\___/ \\__|\n                                  | |              \n                                  |_|              \n";
    std::cout << logo << std::endl << std::endl << std::endl << version << std::endl << std::endl;
}

void TextUserInterface::printBye() {
    std::string bye = 
        "██████╗ ██╗   ██╗███████╗    ██╗\n"
        "██╔══██╗╚██╗ ██╔╝██╔════╝    ██║\n"
        "██████╔╝ ╚████╔╝ █████╗      ██║\n"
        "██╔══██╗  ╚██╔╝  ██╔══╝      ╚═╝\n"
        "██████╔╝   ██║   ███████╗    ██╗\n"
        "╚═════╝    ╚═╝   ╚══════╝    ╚═╝\n";
    std::cout << bye << std::endl;
}