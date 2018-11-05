#include <string>
#include <vector>
#include <fstream>
#include <sqlite3.h>
#include <bits/unique_ptr.h>

#include "../EventHandler/EventHandler.hpp"
#include "OrderHandler.hpp"
#include "../../TechnicalServices/DatabaseConnector/DatabaseConnector.hpp"
#include "../../TechnicalServices/Logger/Logger.hpp"

#include <stdlib.h>
#include <time.h>

OrderHandler::OrderHandler(int userid) {
    session_userid = userid;
}

// generate a random number in between lowerBound and upperBound
int OrderHandler::getRandomNumber(int lowerBound, int upperBound) {
    srand(time(NULL));
    return rand() % upperBound + lowerBound;
}

// create order and persist that order into DB using DatabaseConnector
int OrderHandler::createOrder(int UPC, int quantity, int payid) {
    int orderid = this->getRandomNumber(1, 1000000);

    // create DatabaseConnector object
    std::unique_ptr<DatabaseConnector> db(new DatabaseConnector("test.db"));
    // persist order into db
    db->OrderCreate(orderid, session_userid, UPC, quantity, payid);

    // log order event
    std::unique_ptr<Logger> logger(new Logger("test.log"));
    std::string msg = "Order " + std::to_string(orderid) + " created by Customer-" + std::to_string(session_userid) + " with PayID-"+std::to_string(payid);
    logger->log("USER", session_userid, msg);

    return orderid;
}

// create payment and persist that payment into DB using DatabaseConnector
int OrderHandler::createPayment(std::string method, std::string amount, int refund) {
    int payid = this->getRandomNumber(1, 1000000);
    // create DatabaseConnector object
    std::unique_ptr<DatabaseConnector> db(new DatabaseConnector("test.db"));
    // persist payment into DB
    db->PaymentCreate(payid, session_userid, method, amount, refund);

    // log this payment
    std::unique_ptr<Logger> logger(new Logger("test.log"));
    std::string msg = "Payment "+std::to_string(payid)+" created by Customer-"+std::to_string(session_userid)+" with amount $-"+amount;
    logger->log("USER", session_userid, msg);

    return payid;
}