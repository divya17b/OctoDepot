#ifndef AUDITORMENU_HPP
#define AUDITORMENU_HPP

// use this class when the user permission is 200
class AuditorMenu : public Menu {

public:
    AuditorMenu(int userid);
    ~AuditorMenu();
    // initialize content of menu
    void initSelections();
    void takeSelection();
    // void getLog();
    // void sessionLoop();
};

#endif