#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <string>

class Logger {
  private:
    std::string logOutputLine;
  public:
    Logger();
    ~Logger();
};

#endif
