#include <string>
#include <iostream>
#include <bits/unique_ptr.h>
#include "Menu.hpp"
#include "CustomerMenu.hpp"
#include "../../Domain/OrderHandler/OrderHandler.hpp"

CustomerMenu::CustomerMenu(int userid) {
    // store a copy of user id in local class
    session_userid = userid;
}

CustomerMenu::~CustomerMenu() {}

void CustomerMenu::initSelections() {
    menu = "Customer menu\n-------------------\n1. Place Order Using UPC\n0. Logout";
}
void CustomerMenu::takeSelection() {
    int selection = -1;
    std::cout << "\n: ";
    std::cin >> selection;

    // print selection, debug purpose
    // std::cout << selection << std::endl;

    switch (selection) {
        // option 0 to logout
        case 0:
            this->logout();
            break;
        // option 1 to place order using UPC
        case 1:{
            std::cout << std::endl << "*** Placing Order using UPC ***" << std::endl << std::endl;

            // 1. asking product UPC/quantity and method and amount to pay
            int UPC = this->requestNumeric("UPC: ");
            int quantity = this->requestNumeric("Quantity: ");
            // TODO: call ProductHandler ask what is the subtotal
            std::cout << std::endl << "*** Order Detail ***\nProduct Name: Some Product [UPC:"<< UPC << "]\nQuantity: " << quantity << std::endl;
            std::string yn = this->requestString("Subtotal: $XXXX.XX\n\nPlace Order [Y/n]: ");

            if (yn.empty() || yn == "y" || yn == "Y") {
                std::string method = this->requestString("Please Specify a Payment Method: ");
                std::string amount = this->requestString("Please Enter the amount: ");
                // if user confirms buying, create OrderHandler to create payment and order
                std::unique_ptr<OrderHandler> orderHandler(new OrderHandler(session_userid));
                int payid = orderHandler->createPayment(method, amount, 0);
                int orderid = orderHandler->createOrder(UPC, quantity, payid);
                std::cout << "\nYour order has been placed.\nOrder ID: " << orderid << "\nPayment ID: " << payid << std::endl;
            } else {
                std::cout << "\nOrder Cancelled." << std::endl;
            }
            this->pausePrompt();
            break;
        }
        default:
            break;
    }
}