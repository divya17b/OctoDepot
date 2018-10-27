#ifndef SalespersonMenu_HPP
#define SalespersonMenu_HPP

class SalespersonMenu : public Menu {

public:
    SalespersonMenu();
    void initSelections();
    void takeSelection();
    // void getLog();
    void sessionLoop();
};

#endif