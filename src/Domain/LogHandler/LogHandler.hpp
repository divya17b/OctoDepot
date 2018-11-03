#ifndef LOGHANDLER_HPP
#define LOGHANDLER_HPP

#include "../EventHandler/EventHandler.hpp"

class LogHandler : public EventHandler {

public:
    LogHandler(int userid);
    std::vector<std::string> getLog(std::string startTime, std::string endTime);
};

#endif