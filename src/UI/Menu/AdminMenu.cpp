#include <string>
#include <iostream>
#include "Menu.hpp"
#include "AdminMenu.hpp"

AdminMenu::AdminMenu() {
}

void AdminMenu::initSelections() {
    menu = "Admin menu\n-------------------\n1. Modify Customer Information\n0. Logout";
}
void AdminMenu::takeSelection() {
    int selection = -1;
    std::cout << ": ";
    std::cin >> selection;

    // print selection, debug purpose
    // std::cout << selection << std::endl;

    switch (selection) {
        case 0:
            this->logout();
            break;
        case 1:
            std::cout << "Modifying Customer Information !!" << std::endl;
            break;
        default:
            break;
    }
}

void AdminMenu::sessionLoop() {
    this->initSelections();
    while (isActive) {
        this->displayMenu();
        this->takeSelection();
    }
}