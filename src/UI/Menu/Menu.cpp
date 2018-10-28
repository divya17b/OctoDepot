#include <iostream>
#include <string>
#include "Menu.hpp"

Menu::Menu() {
    isActive = true;
}

void Menu::clearScreen() {
    for (int i=0;i<24;i++) std::cout << std::endl;
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
    selection = this->requestNumeric("\n: ");

    // print selection, debug purpose
    std::cout << selection << std::endl;

    if (selection == 1) {
        this->logout();
    }
}

int Menu::requestNumeric(std::string prompt) {
    int result;
    std::cout << prompt;
    std::cin >> result;
    std::cin.ignore();
    return result;
}
std::string Menu::requestString(std::string prompt) {
    std::string result;
    std::cout << prompt;
    std::getline(std::cin, result);
    return result;
}

void Menu::logout() {
    isActive = false;
}

void Menu::sessionLoop() {
    this->initSelections();
    while (isActive) {
        this->clearScreen();
        this->displayMenu();
        this->takeSelection();
    }
}