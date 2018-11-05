#ifndef CustomerMenu_HPP
#define CustomerMenu_HPP

// use this class when the user permission is 1000
class CustomerMenu : public Menu {

public:
    CustomerMenu(int userid);
    ~CustomerMenu();
    void initSelections();
    void takeSelection();
    // void getLog();
    // void sessionLoop();
};

#endif