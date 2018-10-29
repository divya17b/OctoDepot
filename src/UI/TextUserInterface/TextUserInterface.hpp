#ifndef TextUserInterface_HPP
#define TextUserInterface_HPP

class TextUserInterface {
private:
    std::string version;
    int permission;
    int current_userid;
    bool isActive;

    void clearScreen();
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