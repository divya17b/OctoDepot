#include <string>
#include <fstream>
#include <iostream>
#include <vector>

#include "../EventHandler/EventHandler.hpp"
#include "LogHandler.hpp"
#include "../../TechnicalServices/Logger/Logger.hpp"

LogHandler::LogHandler(int userid) {
    session_userid = userid;
}

std::vector<std::string> LogHandler::getLog(std::string startTime, std::string endTime) {
    Logger logger("test.log");
    std::vector<std::string> result = logger.readLines();
    // it will be empty for now
    // if (!result.empty())
    std::string msg = "Auditor - " + std::to_string(session_userid) + " retrieved system log.";
    logger.log("AUDIT", session_userid, msg);
    return result;
}
