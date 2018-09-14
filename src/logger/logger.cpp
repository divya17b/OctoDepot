#include "logger.hpp"

Logger::Logger() {}
Logger::Logger(logLine l) {
  load_one_line(l);
}
Logger::~Logger() {
  flush();
}

void Logger::flush() {
  buffer = "";
}

int Logger::load_one_line(logLine l) {
  buffer += serialize(l);
  return 1;
}

std::string Logger::serialize(logLine line) {
  return "["+std::to_string(line.timestamp)+" - "+line.indicator+"] " + line.message+"\n";
}

std::string Logger::get_buffer_content(){
  return buffer;
}

void Logger::write_buffer_to_file(std::ofstream &target) {
  if (target.is_open())
    target << buffer;
}
