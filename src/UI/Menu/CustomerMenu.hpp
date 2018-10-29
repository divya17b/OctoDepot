#ifndef CustomerMenu_HPP
#define CustomerMenu_HPP

class CustomerMenu : public Menu {
private:
    int session_userid;
public:
    CustomerMenu(int userid);
    void initSelections();
    void takeSelection();
    // void getLog();
    void sessionLoop();
};

#endif