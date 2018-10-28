#ifndef LOGHANDLER_HPP
#define LOGHANDLER_HPP

class LogHandler {
public:
    LogHandler();
    std::vector<std::string> getLog(std::string startTime, std::string endTime);
};

#endif