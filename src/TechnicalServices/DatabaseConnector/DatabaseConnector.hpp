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

	int ProductCreate(int UPC, std::string product_name, std::string vendor_name, std::string price, std::string description);
	int ProductRemove(int UPC);
	int ProductUpdate(int UPC, std::string product_name, std::string vendor_name, std::string price, std::string description);
	void ProductSearchByUPC(int UPC);
	void ProductSearchByName(std::string product_name);

	int OrderCreate(int orderid, int userid, int UPC, int quantity, int payid);
	int OrderUpdate(int orderid, int userid, int UPC, int quantity, int payid);
	int OrderRemove(int orderid);
	void OrderGetByID(int orderid);
	void OrderSearchByUser(int userid);

	int PaymentCreate(int payid, int userid, std::string method, std::string amount, int refund);
	int PaymentUpdate(int payid, int userid, std::string method, std::string amount, int refund);
	int PaymentRemove(int payid);
};

#endif
