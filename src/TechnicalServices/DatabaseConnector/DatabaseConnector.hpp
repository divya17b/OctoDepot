#ifndef DatabaseConnector_HPP
#define DatabaseConnector_HPP

class DatabaseConnector {

private:
	void connect();
	void disconnect();

public:
	DatabaseConnector();

	void ProductCreate(int productID, int productName, int productPrice, int UPC, int description);
	void ProductUpdate(int productID, int productName, int productPrice, int UPC, int description);
	void ProductGetByID(int productID);
	void ProductSearchByUPC(int UPC);
	void ProductSearchByName(int productName);
	void OrderCreate(int orderID, int productID, int userID, int quantity, int paymentID);
	void OrderUpdate(int orderID, int productID, int userID, int quantity, int paymentID);
	void OrderRemove(int orderID);
	void OrderGetByID(int orderID);
	void OrderSearchByUser(int userid);
	void PaymentCreate(int paymentID);
	void PaymentCreate(int paymentID, int paymentStatus);
	void PaymentUpdate(int paymentID, int paymentStatus);
	void PaymentRemove(int paymentID);
};

#endif
