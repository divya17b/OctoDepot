#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <string>

struct logLine {
  double timestamp;
  std::string indicator;
  std::string message;
};

class Logger {
  public:
    Logger();
    ~Logger();
    int ReadAll();
    int Append();
    std::string serialize(logLine line);
};

#endif
