#ifndef CustomerMenu_HPP
#define CustomerMenu_HPP

class CustomerMenu : public Menu {

public:
    CustomerMenu();
    void initSelections();
    void takeSelection();
    // void getLog();
    void sessionLoop();
};

#endif