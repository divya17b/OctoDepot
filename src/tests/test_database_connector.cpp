#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sqlite3.h>

#include "../TechnicalServices/DatabaseConnector/DatabaseConnector.hpp"

int main() {
  std::cout << "Test for TechnicalServices/Logger" << std::endl;
  // initialize class
  std::cout << "1. initialize class";
  DatabaseConnector db("test.db");
  std::cout << "- Success" << std::endl;
  
  db.Initialize();

  db.UserCreate(7727349, "OctoDepot", "Yoko Kanazuki", "1159 Jeffery Rd, Suite 100, Irvine, CA 92612", "i@noctoid.com", "949-111-2222");

  db.UserModify(7727349, "OctoDepot", "Yoko Kanazuki", "P.O. Box 42, Irvine, CA 92618", "i@noctoid.com", "949-123-4567");
  
  return 0;
}
