#include <string>
#include <iostream>
#include "Menu.hpp"
#include "AdminMenu.hpp"

AdminMenu::AdminMenu() {
}

void AdminMenu::initSelections() {
    menu = "Admin menu\n-------------------\n1. Logout";
}
void AdminMenu::takeSelection() {
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

void AdminMenu::sessionLoop() {
    this->initSelections();
    while (isActive) {
        this->displayMenu();
        this->takeSelection();
    }
}