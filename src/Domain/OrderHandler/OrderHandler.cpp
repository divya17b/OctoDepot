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
    int result = -1;
    srand(time(NULL));
    return rand() % upperBound + lowerBound;
}

int OrderHandler::createOrder(int userid, int UPC, int quantity, int payid) {
    int orderid = this->getRandomNumber(1, 1000000);
    DatabaseConnector db("test.db");
    db.OrderCreate(orderid, userid, UPC, quantity, payid);
    return orderid;
}

int OrderHandler::createPayment(int userid, std::string method, std::string amount, int refund) {
    int payid = this->getRandomNumber(1, 1000000);
    DatabaseConnector db("test.db");
    db.PaymentCreate(payid, userid, method, amount, refund);
    return payid;
}