#ifndef MENU_HPP
#define MENU_HPP

class Menu {

protected:
    bool isActive;
    int current_userid;
    std::string menu;

    void displayMenu();
    void initSelections();
    void takeSelection();
    void logout();

public:
    Menu();
    void sessionLoop();
};

#endif