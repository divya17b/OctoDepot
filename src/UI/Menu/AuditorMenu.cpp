#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include "Menu.hpp"
#include "AuditorMenu.hpp"
#include "../../Domain/LogHandler/LogHandler.hpp"
#include "../../TechnicalServices/Logger/Logger.hpp"

AuditorMenu::AuditorMenu() {
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
            LogHandler mLogHandler;
            std::vector<std::string> results;
            results = mLogHandler.getLog("123", "456");

            for (auto i : results) {
                std::cout << i << std::endl;
            }
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