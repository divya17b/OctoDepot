#ifndef SalespersonMenu_HPP
#define SalespersonMenu_HPP

// use this class when the user permission is 100
class SalespersonMenu : public Menu {

public:
    SalespersonMenu(int userid);
    ~SalespersonMenu();
    void initSelections();
    void takeSelection();
    // int requestNumeric(std::string prompt);
    // std::string requestString(std::string prompt);
    // void sessionLoop();
};

#endif