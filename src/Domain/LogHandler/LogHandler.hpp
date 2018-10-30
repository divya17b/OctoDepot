#ifndef LOGHANDLER_HPP
#define LOGHANDLER_HPP

class LogHandler {
    int session_userid;
public:
    LogHandler(int userid);
    std::vector<std::string> getLog(std::string startTime, std::string endTime);
};

#endif