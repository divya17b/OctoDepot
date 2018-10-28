#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include "../Domain/LogHandler/LogHandler.hpp"
#include "../TechnicalServices/Logger/Logger.hpp"

int main() {
    LogHandler mLogHandler;
    std::vector<std::string> results;
    results = mLogHandler.getLog("123", "456");

    for (auto i : results) {
        std::cout << i << std::endl;
    }
}