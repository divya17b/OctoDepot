#ifndef AdminMenu_HPP
#define AdminMenu_HPP

// use this class when the user permission is 1
class AdminMenu : public Menu {

// this should be the "isActive" of TextUserInterface passed by pointer
// in order to change the status one layer above
bool* parentContinueStatus;

public:
    AdminMenu(int userid, bool* ContinueStatus);
    ~AdminMenu();
    void initSelections();
    void takeSelection();
    // void getLog();
    // void sessionLoop();
};

#endif