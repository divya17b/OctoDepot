#ifndef DatabaseConnector_HPP
#define DatabaseConnector_HPP

class DatabaseConnector {

private:
	std::string db_name;
	sqlite3 *db;
	int rc;
	void connect();
	void disconnect();
	static int callback(void *NotUsed, int argc, char **argv, char **azColName);
public:
	DatabaseConnector(std::string db_file_name);

	void CreateTables();

	void Initialize();
	int UserCreate(int userid, std::string company_name, std::string contact_name, std::string address, std::string email,std::string phone);
	int UserRemove(int userid);
	int UserModify(int userid, std::string company_name, std::string contact_name, std::string address, std::string email,std::string phone);

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
