#ifndef EVENTHANDLER_HPP
#define EVENTHANDLER_HPP

// this is the abstract class which has the common 
// things all eventhandler will share
class EventHandler {
protected:
    // the user id of whom owns the current session
    int session_userid;
};

#endif