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

  std::cout << "------ User Create ------" << std::endl;
  db.UserCreate(7727349, "OctoDepot", "Yoko Kanazuki", "1159 Jeffery Rd, Suite 100, Irvine, CA 92612", "i@noctoid.com", "949-111-2222");

  db.UserModify(7727349, "OctoDepot", "Yoko Kanazuki", "P.O. Box 42, Irvine, CA 92618", "i@noctoid.com", "949-123-4567");

  std::cout << "------ Product Create ------" << std::endl;
  db.ProductCreate(123456, "Test Product 1", "Test Vendor 1", "123.45", "Real good product.");
  db.ProductCreate(234567, "Test Product 2", "Test Vendor 2", "123.45", "Real good product.");
  db.ProductCreate(345678, "Test Product 3", "Test Vendor 3", "123.45", "Real good product.");

  std::cout << "------ Product Update ------" << std::endl;
  db.ProductUpdate(123456, "Test Product 1 Mod", "Test Vendor 1 Mod", "234.56", "Modified Real Good product.");
  
  std::cout << "------ Product Search ------" << std::endl;
  db.ProductSearchByUPC(123456);
  db.ProductSearchByName("Test Product 2");
  return 0;
}
