#include <string>
#include <iostream>
#include "Menu.hpp"
#include "CustomerMenu.hpp"

CustomerMenu::CustomerMenu() {
}

void CustomerMenu::initSelections() {
    menu = "Customer menu\n-------------------\n1. Place Order Using UPC\n0. Logout";
}
void CustomerMenu::takeSelection() {
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
            std::cout << "assume you are placing order" << std::endl;
            break;
        default:
            break;
    }
}

void CustomerMenu::sessionLoop() {
    this->initSelections();
    while (isActive) {
        this->displayMenu();
        this->takeSelection();
    }
}