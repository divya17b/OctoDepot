#ifndef AUDITORMENU_HPP
#define AUDITORMENU_HPP

class AuditorMenu : public Menu {

public:
    AuditorMenu(int userid);
    void initSelections();
    void takeSelection();
    // void getLog();
    void sessionLoop();
};

#endif