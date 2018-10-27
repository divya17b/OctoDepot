#include <iostream>
#include <string>
#include "Menu.hpp"

Menu::Menu() {
    isActive = true;
}
void Menu::displayMenu() {
    std::cout << menu << std::endl;
}

void Menu::initSelections() {
    menu = "template menu\n 1. logout";
}

void Menu::takeSelection() {
    // not consider wrong input
    // trusting user input :)
    int selection = -1;
    std::cout << "=> ";
    std::cin >> selection;

    // print selection, debug purpose
    std::cout << selection << std::endl;

    if (selection == 1) {
        this->logout();
    }
}

void Menu::logout() {
    isActive = false;
}

void Menu::sessionLoop() {
    this->initSelections();
    while (isActive) {
        this->displayMenu();
        this->takeSelection();
    }
}