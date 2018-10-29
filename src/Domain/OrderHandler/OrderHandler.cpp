#include <string>
#include <sqlite3.h>
#include "OrderHandler.hpp"
#include "../../TechnicalServices/DatabaseConnector/DatabaseConnector.hpp"

#include <stdlib.h>
#include <time.h>

OrderHandler::OrderHandler(int userid) {
    current_userid = userid;
}

int OrderHandler::getRandomNumber(int lowerBound, int upperBound) {
    srand(time(NULL));
    return rand() % upperBound + lowerBound;
}

int OrderHandler::createOrder(int UPC, int quantity, int payid) {
    int orderid = this->getRandomNumber(1, 1000000);
    DatabaseConnector db("test.db");
    db.OrderCreate(orderid, current_userid, UPC, quantity, payid);
    return orderid;
}

int OrderHandler::createPayment(std::string method, std::string amount, int refund) {
    int payid = this->getRandomNumber(1, 1000000);
    DatabaseConnector db("test.db");
    db.PaymentCreate(payid, current_userid, method, amount, refund);
    return payid;
}