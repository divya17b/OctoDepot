#ifndef MENU_HPP
#define MENU_HPP

class Menu {

protected:
    bool isActive;
    int session_userid;
    std::string menu;

    void clearScreen();
    void displayMenu();
    virtual void initSelections() = 0;
    virtual void takeSelection() = 0;
    int requestNumeric(std::string prompt);
    std::string requestString(std::string prompt);
    void pausePrompt();
    void logout();

public:
    // Menu();
    void sessionLoop();
};

#endif