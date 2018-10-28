#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sqlite3.h>

#include "../Domain/UserHandler/UserHandler.hpp"
#include "../TechnicalServices/DatabaseConnector/DatabaseConnector.hpp"

int main() {
  std::cout << "Test for TechnicalServices/Logger" << std::endl;
  // initialize class
  std::cout << "1. initialize class";
  UserHandler userHandler;
  std::cout << "- Success" << std::endl;

  std::string company_name = "OctoDepot";
  std::string contact_name = "Yoko Kanazuki";
  std::string address = "1159 Jeffery Rd, Suite 100, Irvine, CA 92612";
  std::string email = "i@noctoid.com";
  std::string phone = "949-111-2222";
  
//   int userid = userHandler.createUser(company_name, contact_name, address, email, phone);
    int userid = userHandler.createUser("OctoDepot", "Yoko Kanazuki", "1159 Jeffery Rd, Suite 100, Irvine, CA 92612", "i@noctoid.com", "949-111-2222");
  std::cout << userid << std::endl;
  
  return 0;
}
