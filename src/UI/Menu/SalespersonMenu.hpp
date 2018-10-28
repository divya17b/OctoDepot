#ifndef SalespersonMenu_HPP
#define SalespersonMenu_HPP

class SalespersonMenu : public Menu {

public:
    SalespersonMenu();
    void initSelections();
    void takeSelection();
    // int requestNumeric(std::string prompt);
    // std::string requestString(std::string prompt);
    void sessionLoop();
};

#endif