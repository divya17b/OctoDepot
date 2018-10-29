#ifndef ORDERHANDLER_HPP
#define ORDERHANDLER_HPP

class OrderHandler {
private:
    int current_userid;
    int getRandomNumber(int lowerBound, int upperBound);

public:
    OrderHandler(int userid);
    int createOrder(int userid, int UPC, int quantiry, int payid);
    int createPayment(int userid, std::string method, std::string amount, int refund);
};

#endif