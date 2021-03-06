#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <bits/unique_ptr.h>
#include "Menu.hpp"
#include "AuditorMenu.hpp"
#include "../../Domain/LogHandler/LogHandler.hpp"

AuditorMenu::AuditorMenu(int userid) {
    // store a copy of user id in local class
    session_userid = userid;
}

AuditorMenu::~AuditorMenu() {}

void AuditorMenu::initSelections() {
    menu = "Auditor menu\n-------------------\n1. Get System Log\n0. Logout";
}
void AuditorMenu::takeSelection() {
    int selection = -1;
    std::cout << "\n: ";
    std::cin >> selection;

    // print selection, debug purpose
    // std::cout << selection << std::endl;

    switch (selection) {
        // option 0 to logout
        case 0: {
            this->logout();
            break;
        // option 1 to retieve system log
        // 1. ask user start time, end time, location to save the log (next increment)
        // 2. retrieve log
        } case 1: {
            std::cout << std::endl << "*** Retrieve System Log ***" << std::endl << std::endl;
            // create new LogHandler object to get the system log
            std::unique_ptr<LogHandler> mLogHandler(new LogHandler(session_userid));
            std::vector<std::string> results;
            results = mLogHandler->getLog("123", "456");

            for (auto i : results) {
                std::cout << i << std::endl;
            }
            std::cout << "Log Retrieved by Auditor-" << session_userid << std::endl;

            this->pausePrompt();
            break;
        } default:
            std::cout << "Invalid option" << std::endl;
    }
}