#ifndef MENU_HPP
#define MENU_HPP

// this is the interface class of all Menus
class Menu {

protected:
    // true session still up, false to terminate session
    bool isActive;
    // Current User ID who is using this session
    int session_userid;
    // the Menu itself in string
    std::string menu;

    // clear current screen content
    void clearScreen();
    // print menu to console
    void displayMenu();
    // initialize the menu content, to be expanded by subclasses
    virtual void initSelections() = 0;
    // take action when user give a selection on menu options
    // to be expanded by each subclasses
    virtual void takeSelection() = 0;
    // request numeric input by user
    int requestNumeric(std::string prompt);
    // request string input by user
    std::string requestString(std::string prompt);
    // press ENTER to continue
    void pausePrompt();
    // terminate current session
    void logout();

public:
    // Menu();
    void sessionLoop();
};

#endif