#ifndef TextUserInterface_HPP
#define TextUserInterface_HPP

// this is the major UI class that drives the entire user interface
// also, this class is where you want to start to run the entire project
// What this class does:
// 1. ask user for user id and password to log in
// 2. get permission by creating an AuthorizationHandler object and call authenticate upon it
// 3. for different types of users, give their Menu accordingly.
// What information will this class hold
// 1. version number of the system
// 2. permission of current logged in user
// 3. User ID of current logged in user
// 4. current running status: true for up, false for shutdown

class TextUserInterface {
private:
    // version number
    std::string version;
    // permission of current logged in user
    // default is -1 for not logged in
    int permission;
    // User ID current logged in
    int current_userid;

    // method to clean current screen content
    void clearScreen();
    // method to ask user their user id
    int askUserID();
    // method to ask user their password
    std::string askUserPassword();

public:
    // running or shutdown
    bool isActive;

    // constructor
    TextUserInterface();
    // print a nice looking OctoDepot logo
    void printLogo();
    // print a nice looking Bye
    void printBye();
    // integrated method to 
    // 1. ask user id and password
    // 2. verify that id and password using AuthorizationHandler
    // 3. store the permission and user id into this object
    void login();
    // start a session by given the responding Menu to the verified permission
    // 1 - admin session using AdminMenu
    // 100 - salesperson session using SalespersonMenu
    // 200 - auditor session using AuditorMenu
    // 1000 - customer session using CustomerMenu
    // -1 - say sorry
    void startSession();
    // not used - to be removed by next increment
    void shutdown();
    // the main loop to start every logic
    // detail see the Main loop UML sequence diagram
    void MainLoop();
};

#endif