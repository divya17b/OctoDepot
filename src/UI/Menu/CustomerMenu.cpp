#include <string>
#include <iostream>
#include "Menu.hpp"
#include "CustomerMenu.hpp"
#include "../../Domain/OrderHandler/OrderHandler.hpp"

CustomerMenu::CustomerMenu(int userid) {
    session_userid = userid;
}

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
        case 0:
            this->logout();
            break;
        case 1:{
            std::cout << std::endl << "*** Placing Order using UPC ***" << std::endl << std::endl; 

            int UPC = this->requestNumeric("UPC: ");
            int quantity = this->requestNumeric("Quantity: ");
            // TODO: call ProductHandler ask what is the subtotal
            std::string yn = this->requestString("Subtotal: $????.??\nPlace Order [Y/n]: ");

            if (yn.empty() || yn == "y" || yn == "Y") {
                std::string method = this->requestString("Please Specify a Payment Method: ");
                std::string amount = this->requestString("Please Enter the amount: ");
                
                OrderHandler orderHandler(session_userid);
                int payid = orderHandler.createPayment(method, amount, 0);
                int orderid = orderHandler.createOrder(UPC, quantity, payid);
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

void CustomerMenu::sessionLoop() {
    this->initSelections();
    this->clearScreen();
    while (isActive) {
        this->displayMenu();
        this->takeSelection();
    }
}