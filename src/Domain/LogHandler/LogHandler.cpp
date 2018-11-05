#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <bits/unique_ptr.h>

#include "../EventHandler/EventHandler.hpp"
#include "LogHandler.hpp"
#include "../../TechnicalServices/Logger/Logger.hpp"

LogHandler::LogHandler(int userid) {
    // store a copy of user id in local class
    session_userid = userid;
}

// get the system log from desired start time to end time into desired location
std::vector<std::string> LogHandler::getLog(std::string startTime, std::string endTime) {
    // remove unused warning lol :)
    startTime + endTime;
    // create logger class to read log from
    std::unique_ptr<Logger> logger(new Logger("test.log"));
    std::vector<std::string> result = logger->readLines();
    // it will be empty for now
    // if (!result.empty())
    std::string msg = "Auditor - " + std::to_string(session_userid) + " retrieved system log.";
    logger->log("AUDIT", session_userid, msg);
    return result;
}
