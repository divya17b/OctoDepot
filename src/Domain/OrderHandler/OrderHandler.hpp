#ifndef ORDERHANDLER_HPP
#define ORDERHANDLER_HPP

class OrderHandler {
private:
    int current_userid;
    int getRandomNumber(int lowerBound, int upperBound);

public:
    OrderHandler(int userid);
    int createOrder(int UPC, int quantity, int payid);
    int createPayment(std::string method, std::string amount, int refund);
};

#endif