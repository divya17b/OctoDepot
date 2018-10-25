#include <iostream>
#include <fstream>
#include <vector>

// #include "logger/logger.hpp"

#include "TechnicalServices/Logger/Logger.hpp"

int main() {
  // logLine warn = {.timestamp=12.3456789, .indicator="WARNING", .message="too much milk in coffee!"};
  // logLine err = {.timestamp=22.3456789, .indicator="ERROR", .message="no milk for making coffee!"};
  // logLine info = {.timestamp=32.3456789, .indicator="INFO", .message="just bought new beans."};
  //
  // Logger logger(warn);
  // std::cout << logger.get_buffer_content();
  // logger.load_one_line(err);
  // std::cout << logger.get_buffer_content();
  // logger.load_one_line(info);
  // std::cout << logger.get_buffer_content();
  //
  // std::ofstream logfile("foobar.log", std::ios_base::app);
  // logger.write_buffer_to_file(logfile);
  // logfile.close();
  //
  // logger.flush();
  // std::cout << "should be nothing following >> " << logger.get_buffer_content() << "\n";


  // TODO for TechnicalServices/Logger
  std::cout << "Test for TechnicalServices/Logger\n";
  Logger logger("test.log");
  for (int i=0; i<5; ++i) logger.writeLine("this is a test line");
  return 0;
}
