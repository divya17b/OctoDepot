#ifndef ORDERHANDLER_HPP
#define ORDERHANDLER_HPP

#include "../EventHandler/EventHandler.hpp"

// expanding EventHandler class, added create order and create payment
class OrderHandler : public EventHandler  {
private:
    // generate random number
    int getRandomNumber(int lowerBound, int upperBound);

public:
    OrderHandler(int userid);
    // create order and persist that order into DB using DatabaseConnector
    int createOrder(int UPC, int quantity, int payid);
    // create payment and persist that payment into DB using DatabaseConnector
    int createPayment(std::string method, std::string amount, int refund);
};

#endif