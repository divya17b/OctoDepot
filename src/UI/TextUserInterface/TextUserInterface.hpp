#ifndef TextUserInterface_HPP
#define TextUserInterface_HPP

class TextUserInterface {
private:
    int permission;
    int current_userid;
    bool isActive;

    int askUserID();
    std::string askUserPassword();

public:
    TextUserInterface();
    void printLogo();
    void login();
    void startSession();
    void shutdown();
    void MainLoop();
};

#endif