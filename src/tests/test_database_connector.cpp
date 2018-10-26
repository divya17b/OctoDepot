#include <iostream>
#include <fstream>
#include <vector>

#include "../TechnicalServices/DatabaseConnector/DatabaseConnector.hpp"

int main() {
  std::cout << "Test for TechnicalServices/Logger" << std::endl;
  // initialize class
  std::cout << "1. initialize class";
  DatabaseConnector db();
  std::cout << "- Success" << std::endl;
  
  return 0;
}
