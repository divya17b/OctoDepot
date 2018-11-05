#ifndef DatabaseConnector_HPP
#define DatabaseConnector_HPP

// this is the interface to the database itself
class DatabaseConnector {

private:
	// the Database file
	// since sqlite3 is an offline relational database, it will persist all data onto an actual file
	std::string db_name;
	// the pointer to sqlite3 connector object
	sqlite3 *db;
	// required by sqlite3 connector, but not used, removed by next increment
	int rc;
	// initialize connection to sqlite3 database
	void connect();
	// disconnect to sqlite3 database
	void disconnect();
	// retrieving information from SQL query, required by sqlite3 connector
	static int callback(void *NotUsed, int argc, char **argv, char **azColName);
public:
	DatabaseConnector(std::string db_file_name);

	// to be implement in next increment
	void CreateTables();
	// initialize the database, creating tables, not used.
	// to be finished in next increment
	void Initialize();

	// *** User related methods ***
	// Create, Remove, Modify User
	int UserCreate(int userid, std::string company_name, std::string contact_name, std::string address, std::string email,std::string phone);
	int UserRemove(int userid);
	int UserModify(int userid, std::string company_name, std::string contact_name, std::string address, std::string email,std::string phone);

	// *** Product related methods ***
	// Create, Remove, Update Product
	int ProductCreate(int UPC, std::string product_name, std::string vendor_name, std::string price, std::string description);
	int ProductRemove(int UPC);
	int ProductUpdate(int UPC, std::string product_name, std::string vendor_name, std::string price, std::string description);
	// get product information using product UPC
	void ProductSearchByUPC(int UPC);
	// get product information using product name
	void ProductSearchByName(std::string product_name);


	// *** orders related methods ***

	// create
	int OrderCreate(int orderid, int userid, int UPC, int quantity, int payid);
	// update
	int OrderUpdate(int orderid, int userid, int UPC, int quantity, int payid);
	// remove
	int OrderRemove(int orderid);
	// get order information using order ID
	void OrderGetByID(int orderid);
	// get order information using user id
	void OrderSearchByUser(int userid);

	// *** payment related methods ***
	// create
	int PaymentCreate(int payid, int userid, std::string method, std::string amount, int refund);
	// update
	int PaymentUpdate(int payid, int userid, std::string method, std::string amount, int refund);
	// remove
	int PaymentRemove(int payid);
	// todo
	// search payment by payid
	// search payment by userid
};

#endif
