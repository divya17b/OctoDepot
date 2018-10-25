#ifndef LOGGER_H_
#define LOGGER_H_

#include <iostream>
#include <fstream>
#include <string>

// logLine is the datastructure stores each line of log
// which contains the timestamp, info, and message.
// To write line into a log file, call serialize first to
// generate a string
struct logLine {
  double timestamp;
  std::string indicator;
  std::string message;
};

// Main class for generating logger object to be used in controller
class Logger {
  private:
    std::string buffer = "";
    std::string serialize(logLine line);
  public:
    // constructor
    Logger();
    Logger(logLine log_line);
    // deconstructor
    ~Logger();
    void flush();
    int load_one_line(logLine log_line);
    //get log buffer line content, for debug
    std::string get_buffer_content();
    // call this method to write line to a file
    void write_buffer_to_file(std::ofstream &target);

};

#endif
