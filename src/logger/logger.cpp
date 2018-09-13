#include "logger.hpp"

Logger::Logger() {}
Logger::~Logger() {}

std::string Logger::serialize(logLine line) {
  return "["+std::to_string(line.timestamp)+" - "+line.indicator+"] " + line.message+"\n";
}
