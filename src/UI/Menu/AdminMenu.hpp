#ifndef AdminMenu_HPP
#define AdminMenu_HPP

class AdminMenu : public Menu {

public:
    AdminMenu(int userid);
    void initSelections();
    void takeSelection();
    // void getLog();
    void sessionLoop();
};

#endif