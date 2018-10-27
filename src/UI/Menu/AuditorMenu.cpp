#include <string>
#include <iostream>
#include "Menu.hpp"
#include "AuditorMenu.hpp"

AuditorMenu::AuditorMenu() {
}

void AuditorMenu::initSelections() {
    menu = "Auditor menu\n-------------------\n1. Get System Log\n2. Logout";
}
void AuditorMenu::takeSelection() {
    int selection = -1;
    std::cout << ": ";
    std::cin >> selection;

    // print selection, debug purpose
    std::cout << selection << std::endl;

    if (selection == 1) {
        std::cout << "assume you have the log already" << std::endl;
    } else if (selection == 2) {
        this->logout();
    } else {

    }
}

void AuditorMenu::sessionLoop() {
    this->initSelections();
    while (isActive) {
        this->displayMenu();
        this->takeSelection();
    }
}