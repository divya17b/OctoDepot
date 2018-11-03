#ifndef ORDERHANDLER_HPP
#define ORDERHANDLER_HPP

#include "../EventHandler/EventHandler.hpp"

class OrderHandler : public EventHandler  {
private:
    int getRandomNumber(int lowerBound, int upperBound);

public:
    OrderHandler(int userid);
    int createOrder(int UPC, int quantity, int payid);
    int createPayment(std::string method, std::string amount, int refund);
};

#endif