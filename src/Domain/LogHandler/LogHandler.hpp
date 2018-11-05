#ifndef LOGHANDLER_HPP
#define LOGHANDLER_HPP

#include "../EventHandler/EventHandler.hpp"

// Expanding EventHandler class, added getLog method for auditor to retrieve system log
class LogHandler : public EventHandler {

public:
    LogHandler(int userid);
    // get the system log from desired start time to end time into desired location
    std::vector<std::string> getLog(std::string startTime, std::string endTime);
};

#endif