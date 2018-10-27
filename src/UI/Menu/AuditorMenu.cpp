#include <string>
#include <iostream>
#include "Menu.hpp"
#include "AuditorMenu.hpp"

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
        case 0:
            this->logout();
            break;
        case 1:
            std::cout << "assume you have the log already" << std::endl;
            break;
        default:
            break;
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