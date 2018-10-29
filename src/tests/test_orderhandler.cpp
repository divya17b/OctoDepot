#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sqlite3.h>

#include "../Domain/OrderHandler/OrderHandler.hpp"
#include "../TechnicalServices/DatabaseConnector/DatabaseConnector.hpp"

int main() {
  std::cout << "Test for Domain/OrderHandler" << std::endl;
  // initialize class
  std::cout << "1. initialize class";
  OrderHandler orderHandler(7727349);
  std::cout << "- Success" << std::endl;

  // std::string company_name = "OctoDepot";
  // std::string contact_name = "Yoko Kanazuki";
  // std::string address = "1159 Jeffery Rd, Suite 100, Irvine, CA 92612";
  // std::string email = "i@noctoid.com";
  // std::string phone = "949-111-2222";
  
  int payid = orderHandler.createPayment("visa", "240", 0);
  int orderid = orderHandler.createOrder(123456, 120, payid);
  std::cout << "OrderID: " << orderid << std::endl << "Payment ID: " << payid << std::endl;

//   std::string company_name, contact_name, address, email, phone;
//   company_name = userHandler.requestString("Company Name: ");
//   contact_name = userHandler.requestString("Contact Name: ");
//   address      = userHandler.requestString("Address: ");
//   email        = userHandler.requestString("Email: ");
//   phone        = userHandler.requestString("Phone: ");
//   int userid = userHandler.createUser(company_name, contact_name, address, email, phone);
  
  return 0;
}
