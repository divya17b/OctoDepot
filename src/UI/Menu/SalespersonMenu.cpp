#include <string>
#include <iostream>
#include "Menu.hpp"
#include "SalespersonMenu.hpp"

SalespersonMenu::SalespersonMenu() {
}

void SalespersonMenu::initSelections() {
    menu = "Salesperson menu\n-------------------\n1. Logout";
}
void SalespersonMenu::takeSelection() {
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

void SalespersonMenu::sessionLoop() {
    this->initSelections();
    while (isActive) {
        this->displayMenu();
        this->takeSelection();
    }
}