#include <string>
#include <vector>
#include <fstream>
#include <sqlite3.h>
#include "OrderHandler.hpp"
#include "../../TechnicalServices/DatabaseConnector/DatabaseConnector.hpp"
#include "../../TechnicalServices/Logger/Logger.hpp"

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

    // log order event
    Logger logger("test.log");
    std::string msg = "Order " + std::to_string(orderid) + " created by Customer-" + std::to_string(current_userid) + " with PayID-"+std::to_string(payid);
    logger.log("USER", current_userid, msg);

    return orderid;
}

int OrderHandler::createPayment(std::string method, std::string amount, int refund) {
    int payid = this->getRandomNumber(1, 1000000);
    DatabaseConnector db("test.db");
    db.PaymentCreate(payid, current_userid, method, amount, refund);

    // log this payment
    Logger logger("test.log");
    std::string msg = "Payment "+std::to_string(payid)+" created by Customer-"+std::to_string(current_userid)+" with amount $-"+amount;
    logger.log("USER", current_userid, msg);

    return payid;
}