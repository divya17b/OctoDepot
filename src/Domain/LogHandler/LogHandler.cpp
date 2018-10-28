#include <string>
#include <fstream>
#include <iostream>
#include <vector>

#include "LogHandler.hpp"
#include "../../TechnicalServices/Logger/Logger.hpp"

LogHandler::LogHandler() {}

std::vector<std::string> LogHandler::getLog(std::string startTime, std::string endTime) {
    Logger logger("test.log");
    return logger.readLines();
}
