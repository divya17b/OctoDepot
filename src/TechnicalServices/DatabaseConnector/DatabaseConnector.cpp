#include <string>
#include <iostream>
#include <sqlite3.h>

#include "DatabaseConnector.hpp"

DatabaseConnector::DatabaseConnector(std::string db_file_name) {
	// store db location in local class
	db_name = db_file_name;
}

// initialize a database connection
void DatabaseConnector::connect() {
	sqlite3_open(db_name.c_str(), &db);
}
// close a database connection
void DatabaseConnector::disconnect() {
	sqlite3_close(db);
}

// the NotUsed pointer will give a unused variable warning, but this pointer is required by
// sqlite3_exec method; it's original intent is to store the result of the query; however, 
// we have not been so far for this increment.
int DatabaseConnector::callback(void *NotUsed, int argc, char **argv, char **azColName) {
	int i;
	for(i=0; i<argc; i++) {
		std::cout<< azColName[i] << " = " << (argv[i] ? argv[i] : "NULL")<<"\n";
	}
	std::cout<<"\n";
	return 0;
}

// not used except in tests.
// initialize database and creating tables
void DatabaseConnector::Initialize() {
	this->connect();
	char *zErrMsg = 0;
	const char *sqla = "DROP TABLE user";
	const char *sqlb = "DROP TABLE product";
	const char *sqlc = "DROP TABLE orders";
	const char *sqld = "DROP TABLE payment";
	const char *sql1 = "CREATE TABLE user (userid INT PRIMARY KEY, company_name TEXT, contact_name TEXT, address TEXT, email TEXT, phone TEXT)";
	const char *sql2 = "CREATE TABLE orders (orderid INT PRIMARY KEY, userid INT, UPC INT, quantity INT, payid INT)";
	const char *sql3 = "CREATE TABLE product (UPC INT PRIMARY KEY, product_name TEXT, vendor_name TEXT, price REAL, description TEXT)";
	const char *sql4 = "CREATE TABLE payment (payid INT PRIMARY KEY, userid INT, method TEXT, amount REAL, refund INT)";
	sqlite3_exec(db, sqla, this->callback, 0, &zErrMsg);
	// std::cout << zErrMsg << std::endl;
	sqlite3_exec(db, sqlb, this->callback, 0, &zErrMsg);
	// std::cout << zErrMsg << std::endl;
	sqlite3_exec(db, sqlc, this->callback, 0, &zErrMsg);
	// std::cout << zErrMsg << std::endl;
	sqlite3_exec(db, sqld, this->callback, 0, &zErrMsg);
	// std::cout << zErrMsg << std::endl;
	sqlite3_exec(db, sql1, this->callback, 0, &zErrMsg);
	// std::cout << zErrMsg << std::endl;
	sqlite3_exec(db, sql2, this->callback, 0, &zErrMsg);
	// std::cout << zErrMsg << std::endl;
	sqlite3_exec(db, sql3, this->callback, 0, &zErrMsg);
	// std::cout << zErrMsg << std::endl;
	sqlite3_exec(db, sql4, this->callback, 0, &zErrMsg);
	// std::cout << zErrMsg << std::endl;
	this->disconnect();
}

// create user
int DatabaseConnector::UserCreate(
	int userid, 
	std::string company_name,
	std::string contact_name,
	std::string address,
	std::string email,
	std::string phone
)
{
	// open database connection
	this->connect();
	// place to capture error messages
	char *zErrMsg = 0;
	// SQL query to create user
	std::string sql = "INSERT INTO user (userid, company_name, contact_name, address, email, phone) values ('"+std::to_string(userid)+"','"+company_name+"','"+contact_name+"','"+address+"','"+email+"','"+phone+"')";
	// run the SQL query
	sqlite3_exec(db, sql.c_str(), this->callback, 0, &zErrMsg);
	// get information about the user we just created
	std::string sql1 = "SELECT * FROM user";
	sqlite3_exec(db, sql1.c_str(), this->callback, 0, &zErrMsg);
	// close database connection
	this->disconnect();
	// give back the user id of the use we just created
	return userid;
}

// remove user
int DatabaseConnector::UserRemove(int userid) {
	// open database connection
	this->connect();
	// place to store error messages
	char *zErrMsg = 0;

	// SQL query to delete user using their UserID
	std::string sql = "DELETE FROM user WHERE userid = '"+std::to_string(userid)+"'";

	// run the query
	sqlite3_exec(db, sql.c_str(), this->callback, 0, &zErrMsg);
	// std::string sql1 = "SELECT * FROM user";
	// sqlite3_exec(db, sql1.c_str(), this->callback, 0, &zErrMsg);

	// close the database connection
	this->disconnect();
	return userid;
}

int DatabaseConnector::UserModify(int userid, std::string company_name, std::string contact_name, std::string address, std::string email,std::string phone) {
	// remove the user first
	this->UserRemove(userid);
	// create a new one using modified information
	this->UserCreate(userid, company_name, contact_name, address, email, phone);
	// give back userid
	return userid;
}

// Create New Product
// (UPC INT PRIMARY KEY, product_name TEXT, vendor_name TEXT, price REAL, description TEXT)
int DatabaseConnector::ProductCreate(int UPC, std::string product_name, std::string vendor_name, std::string price, std::string description) {
	// 1. open db
	// 2. run SQL query
	// 3. get information from product we just created
	// 4. close db connection
	// 5. give back the UPC we just created
	this->connect();
	char *zErrMsg = 0;
	std::string sql = "INSERT INTO product (UPC, product_name, vendor_name, price, description) values ('"+std::to_string(UPC)+"','"+product_name+"','"+vendor_name+"','"+price+"','"+description+"')";
	sqlite3_exec(db, sql.c_str(), this->callback, 0, &zErrMsg);
	std::string sql1 = "SELECT * FROM product WHERE UPC = '"+std::to_string(UPC)+"'";
	sqlite3_exec(db, sql1.c_str(), this->callback, 0, &zErrMsg);
	this->disconnect();
	return UPC;
}


// Remove product
int DatabaseConnector::ProductRemove(int UPC){
	// 1. open db
	// 2. run SQL to remove product using its UPC code
	// 3. disconnect
	// 4. close db
	// 5. give back the UPC of product we just removed
	this->connect();
	char *zErrMsg = 0;
	std::string sql = "DELETE FROM product WHERE UPC = '"+std::to_string(UPC)+"'";
	sqlite3_exec(db, sql.c_str(), this->callback, 0, &zErrMsg);
	this->disconnect();
	return UPC;
}

// Update Product
int DatabaseConnector::ProductUpdate(int UPC, std::string product_name, std::string vendor_name, std::string price, std::string description) {
	// 1. remove old product
	// 2. create new one using new information
	// 3. give back UPC
	this->ProductRemove(UPC);
	this->ProductCreate(UPC, product_name, vendor_name, price, description);
	return UPC;
}

// Search a product using UPC
void DatabaseConnector::ProductSearchByUPC(int UPC) {
	// 1. connect db
	// 2. run SQL query to find product using UPC
	// 3. print out information about that product (to be change in next increment)
	// 4. disconnect db
	this->connect();
	char *zErrMsg = 0;
	std::cout << UPC << std::endl;
	std::string sql1 = "SELECT * FROM product WHERE UPC = '"+std::to_string(UPC)+"'";
	sqlite3_exec(db, sql1.c_str(), this->callback, 0, &zErrMsg);
	this->disconnect();
	// return UPC;
}

// Search a product using name
void DatabaseConnector::ProductSearchByName(std::string product_name) {
	// 1. connect db
	// 2. run SQL query to find product using exact name
	// 3. print out information about that product (to be change in next increment)
	// 4. disconnect db
	this->connect();
	char *zErrMsg = 0;
	std::string sql1 = "SELECT * FROM product WHERE product_name = '"+product_name+"'";
	sqlite3_exec(db, sql1.c_str(), this->callback, 0, &zErrMsg);
	this->disconnect();
}

// create order
// orderid INT PRIMARY KEY, userid INT, UPC INT, quantity INT, payid INT
int DatabaseConnector::OrderCreate(int orderid, int userid, int UPC, int quantity, int payid) {
	this->connect();
	char *zErrMsg = 0;
	std::string sql = "INSERT INTO orders (orderid, userid, UPC, quantity, payid) values ('"+std::to_string(orderid)+"','"+std::to_string(userid)+"','"+std::to_string(UPC)+"','"+std::to_string(quantity)+"','"+std::to_string(payid)+"')";
	// std::string sql = "INSERT INTO orders (orderid, userid, UPC, quantity, payid) values (1,2,3,4,5)";
	sqlite3_exec(db, sql.c_str(), this->callback, 0, &zErrMsg);
	// std::cout << zErrMsg << std::endl;
	std::string sql1 = "SELECT * FROM orders WHERE orderid = '"+std::to_string(orderid)+"'";
	sqlite3_exec(db, sql1.c_str(), this->callback, 0, &zErrMsg);
	// std::cout << zErrMsg << std::endl;
	this->disconnect();
	return orderid;
}

// update order
int DatabaseConnector::OrderUpdate(int orderid, int userid, int UPC, int quantity, int payid) {
	// 1. remove old one
	// 2. create new one
	// 3. give back order id
	this->OrderRemove(orderid);
	this->OrderCreate(orderid, userid, UPC, quantity, payid);
	return orderid;
}

// remove order
int DatabaseConnector::OrderRemove(int orderid) {
	// 1. open db
	// 2. run SQL to remove order using its order ID
	// 3. disconnect
	// 4. close db
	// 5. give back the order id we just removed
	this->connect();
	char *zErrMsg = 0;
	std::string sql = "DELETE FROM orders WHERE orderid = '"+std::to_string(orderid)+"'";
	sqlite3_exec(db, sql.c_str(), this->callback, 0, &zErrMsg);
	this->disconnect();
	return orderid;
}

// get an order information using its id
void DatabaseConnector::OrderGetByID(int orderid) {
	// 1. connect db
	// 2. run SQL query to find order using orderid
	// 3. print out information about that order (to be change in next increment)
	// 4. disconnect db
	this->connect();
	char *zErrMsg = 0;
	std::string sql1 = "SELECT * FROM orders WHERE orderid = '"+std::to_string(orderid)+"'";
	sqlite3_exec(db, sql1.c_str(), this->callback, 0, &zErrMsg);
	this->disconnect();
}

// find an order information using who ordered
void DatabaseConnector::OrderSearchByUser(int userid) {
	// 1. connect db
	// 2. run SQL query to find order using userid
	// 3. print out information about that order (to be change in next increment)
	// 4. disconnect db
	this->connect();
	char *zErrMsg = 0;
	std::string sql1 = "SELECT * FROM orders WHERE userid = '"+std::to_string(userid)+"'";
	sqlite3_exec(db, sql1.c_str(), this->callback, 0, &zErrMsg);
	this->disconnect();
}


// create payment
// payid INT PRIMARY KEY, userid, INT, method TEXT, amount REAL, refund INT
int DatabaseConnector::PaymentCreate(int payid, int userid, std::string method, std::string amount, int refund) {
	// 1. open db
	// 2. run SQL query to create payment
	// 3. get information from payment we just created
	// 4. close db connection
	// 5. give back the payid we just created
	this->connect();
	char *zErrMsg = 0;
	std::string sql = "INSERT INTO payment (payid, userid, method, amount, refund) values ('"+std::to_string(payid)+"','"+std::to_string(userid)+"','"+method+"','"+amount+"','"+std::to_string(refund)+"')";
	// std::string sql = "INSERT INTO orders (orderid, userid, UPC, quantity, payid) values (1,2,3,4,5)";
	sqlite3_exec(db, sql.c_str(), this->callback, 0, &zErrMsg);
	// std::cout << zErrMsg << std::endl;
	std::string sql1 = "SELECT * FROM payment WHERE payid = '"+std::to_string(payid)+"'";
	sqlite3_exec(db, sql1.c_str(), this->callback, 0, &zErrMsg);
	// std::cout << zErrMsg << std::endl;
	this->disconnect();
	return payid;
}

// update payment
int DatabaseConnector::PaymentUpdate(int payid, int userid, std::string method, std::string amount, int refund) {
	// 1. remove old one
	// 2. create new one
	// 3. give back pay id
	this->PaymentRemove(payid);
	this->PaymentCreate(payid, userid, method, amount, refund);
	return payid;
}

// remove payment
int DatabaseConnector::PaymentRemove(int payid) {
	// 1. open db
	// 2. run SQL to remove payment using its pay ID
	// 3. disconnect
	// 4. close db
	// 5. give back the pay id we just removed
	this->connect();
	char *zErrMsg = 0;
	std::string sql = "DELETE FROM payment WHERE payid = '"+std::to_string(payid)+"'";
	sqlite3_exec(db, sql.c_str(), this->callback, 0, &zErrMsg);
	this->disconnect();
	return payid;
}
