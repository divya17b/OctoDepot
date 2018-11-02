#ifndef TextUserInterface_HPP
#define TextUserInterface_HPP

class TextUserInterface {
private:
    std::string version;
    int permission;
    int current_userid;

    void clearScreen();
    int askUserID();
    std::string askUserPassword();

public:
    bool isActive;

    TextUserInterface();
    void printLogo();
    void printBye();
    void login();
    void startSession();
    void shutdown();
    void MainLoop();
};

#endif