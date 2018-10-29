#ifndef MENU_HPP
#define MENU_HPP

class Menu {

protected:
    bool isActive;
    int session_userid;
    std::string menu;

    void clearScreen();
    void displayMenu();
    void initSelections();
    void takeSelection();
    int requestNumeric(std::string prompt);
    std::string requestString(std::string prompt);
    void logout();

public:
    Menu();
    void sessionLoop();
};

#endif