#include <string>
#include <iostream>
#include "Menu.hpp"
#include "SalespersonMenu.hpp"

SalespersonMenu::SalespersonMenu() {
}

void SalespersonMenu::initSelections() {
    menu = "Salesperson menu\n-------------------\n1. Create New Customer Account\n0. Logout";
}
void SalespersonMenu::takeSelection() {
    int selection = -1;
    std::cout << ": ";
    std::cin >> selection;

    // print selection, debug purpose
    std::cout << selection << std::endl;

    switch (selection) {
        case 0:
            this->logout();
            break;
        case 1:
            std::cout << "Assume creating new customers account" << std::endl;
            break;
        default:
            break;
    }
}

void SalespersonMenu::sessionLoop() {
    this->initSelections();
    while (isActive) {
        this->displayMenu();
        this->takeSelection();
    }
}