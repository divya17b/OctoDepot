#include <iostream>
#include <string>
#include "Menu.hpp"

// see detail on comments of menu.hpp

void Menu::clearScreen() {
    for (int i=0;i<24;i++) std::cout << std::endl;
}
void Menu::displayMenu() {
    std::cout << menu << std::endl;
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

void Menu::pausePrompt() {
    std::cout << "\n\nPress ENTER to continue.";
    std::cin.ignore();
}

void Menu::logout() {
    isActive = false;
}

void Menu::sessionLoop() {
    isActive = true;
    this->initSelections();
    this->clearScreen();
    while (isActive) {
        this->clearScreen();
        this->displayMenu();
        this->takeSelection();
    }
}