#ifndef AdminMenu_HPP
#define AdminMenu_HPP

class AdminMenu : public Menu {

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