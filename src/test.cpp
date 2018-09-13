#include <iostream>

#include "logger/logger.hpp"

int main() {
  logLine l;
  l.timestamp = 12.3456789;
  l.indicator = "warning";
  l.message   = "everything is ok!";
  Logger tom;
  std::string result = tom.serialize(l);
  std::cout << result;
  return 0;
}
