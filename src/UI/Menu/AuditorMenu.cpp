#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include "Menu.hpp"
#include "AuditorMenu.hpp"
#include "../../Domain/LogHandler/LogHandler.hpp"

AuditorMenu::AuditorMenu(int userid) {
    session_userid = userid;
}

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
        case 0: {
            this->logout();
            break;
        } case 1: {
            std::cout << std::endl << "*** Retrieve System Log ***" << std::endl << std::endl;
            LogHandler mLogHandler(session_userid);
            std::vector<std::string> results;
            results = mLogHandler.getLog("123", "456");

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

void AuditorMenu::sessionLoop() {
    this->initSelections();
    this->clearScreen();
    while (isActive) {
        this->displayMenu();
        this->takeSelection();
    }
}