#include <iostream>
#include <fstream>
#include <vector>

#include "../TechnicalServices/Logger/Logger.hpp"

int main() {
  std::cout << "Test for TechnicalServices/Logger" << std::endl;
  // initialize class
  std::cout << "1. initialize class";
  Logger logger("test.log");
  std::cout << "- Success" << std::endl;

  // // TEST for write into log files
  // write 1 line
  // std::cout << "2. Write 1 line";
  // std::string test_line = "There is no more milk for making coffee";
  // std::string empty_line = "";
  // int test1_written_line = 0;
  // test1_written_line += logger.writeLine(test_line);
  // test1_written_line += logger.writeLine(empty_line);
  // if ( test1_written_line == 1 )
  //   std::cout << "- Success" << std::endl;
  // else
  //   std::cout << "- Fail" << std::endl;

  // // write N lines
  // std::cout << "3. Write N lines";
  // std::vector<std::string> lines_to_write;
  // for (int n=0; n<10; n++) {
  //   lines_to_write.push_back(std::to_string(n+1));
  // }
  // int lines_written_test2 = logger.writeLines(lines_to_write);
  // if ( lines_written_test2 == 10 )
  //   std::cout << "- Success" << std::endl;
  // else
  //   std::cout << "- Fail" << std::endl;

  // // read lines in log
  // std::cout << "4. read lines";

  // std::vector<std::string> lines = logger.readLines();

  // // std::cout << lines.size() << "!!!" << std::endl;

  // // make sure the there is no test.log or the file is empty
  // // otherwise test will shows fail.
  // if ( lines_to_write.size()+test1_written_line == lines.size())
  //   std::cout << "- Success" << std::endl;
  // else
  //   std::cout << "- Fail" << std::endl;


  std::cout << "5. serialize and write line";

  // std::string l = logger.serialize(123.45678, "TEST", 1, "Test for logger.log and serialize method.");
  // logger.writeLine(l);
  int logged = logger.log("1234564654.45", "TEST", 1, "Test for logger.log and serialize method.");

  if ( logged == 1)
    std::cout << "- Success" << std::endl;
  else
    std::cout << "- Fail" << std::endl;
  
  return 0;
}
