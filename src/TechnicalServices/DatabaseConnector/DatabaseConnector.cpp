#include <string>
#include <iostream>
#include <sqlite3.h>

#include "DatabaseConnector.hpp"

DatabaseConnector::DatabaseConnector(std::string db_file_name) {
	db_name = db_file_name;
	// this->connect();
	// char *zErrMsg = 0;
	// const char *sql1 = "create table myTable (UPC int PRIMARY KEY, name varchar(30))";
	// const char *sql2 = "insert into myTable (UPC, name) values (7355608, 'iPhone')";
	// const char *sql3 = "select * from myTable";
	// sqlite3_exec(db, sql1, this->callback, 0, &zErrMsg);
	// sqlite3_exec(db, sql2, this->callback, 0, &zErrMsg);
	// sqlite3_exec(db, sql3, this->callback, 0, &zErrMsg);
	// this->disconnect();
}

void DatabaseConnector::connect() {
	sqlite3_open(db_name.c_str(), &db);
}
void DatabaseConnector::disconnect() {
	sqlite3_close(db);
}

int DatabaseConnector::callback(void *NotUsed, int argc, char **argv, char **azColName) {
	int i;
	for(i=0; i<argc; i++) {
		std::cout<< azColName[i] << " = " << (argv[i] ? argv[i] : "NULL")<<"\n";
	}
	std::cout<<"\n";
	return 0;
}

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

int DatabaseConnector::UserCreate(
	int userid, 
	std::string company_name,
	std::string contact_name,
	std::string address,
	std::string email,
	std::string phone
)
{
	this->connect();
	char *zErrMsg = 0;
	std::string sql = "INSERT INTO user (userid, company_name, contact_name, address, email, phone) values ('"+std::to_string(userid)+"','"+company_name+"','"+contact_name+"','"+address+"','"+email+"','"+phone+"')";
	sqlite3_exec(db, sql.c_str(), this->callback, 0, &zErrMsg);
	std::string sql1 = "SELECT * FROM user";
	sqlite3_exec(db, sql1.c_str(), this->callback, 0, &zErrMsg);
	this->disconnect();
	return userid;
}

int DatabaseConnector::UserRemove(int userid) {
	this->connect();
	char *zErrMsg = 0;
	std::string sql = "DELETE FROM user WHERE userid = '"+std::to_string(userid)+"'";
	sqlite3_exec(db, sql.c_str(), this->callback, 0, &zErrMsg);
	// std::string sql1 = "SELECT * FROM user";
	// sqlite3_exec(db, sql1.c_str(), this->callback, 0, &zErrMsg);
	this->disconnect();
	return userid;
}

int DatabaseConnector::UserModify(int userid, std::string company_name, std::string contact_name, std::string address, std::string email,std::string phone) {
	this->UserRemove(userid);
	this->UserCreate(userid, company_name, contact_name, address, email, phone);
	return userid;
}

// (UPC INT PRIMARY KEY, product_name TEXT, vendor_name TEXT, price REAL, description TEXT)
int DatabaseConnector::ProductCreate(int UPC, std::string product_name, std::string vendor_name, std::string price, std::string description) {
	this->connect();
	char *zErrMsg = 0;
	std::string sql = "INSERT INTO product (UPC, product_name, vendor_name, price, description) values ('"+std::to_string(UPC)+"','"+product_name+"','"+vendor_name+"','"+price+"','"+description+"')";
	sqlite3_exec(db, sql.c_str(), this->callback, 0, &zErrMsg);
	std::string sql1 = "SELECT * FROM product WHERE UPC = '"+std::to_string(UPC)+"'";
	sqlite3_exec(db, sql1.c_str(), this->callback, 0, &zErrMsg);
	this->disconnect();
	return UPC;
}

int DatabaseConnector::ProductRemove(int UPC){
	this->connect();
	char *zErrMsg = 0;
	std::string sql = "DELETE FROM product WHERE UPC = '"+std::to_string(UPC)+"'";
	sqlite3_exec(db, sql.c_str(), this->callback, 0, &zErrMsg);
	this->disconnect();
	return UPC;
}

int DatabaseConnector::ProductUpdate(int UPC, std::string product_name, std::string vendor_name, std::string price, std::string description) {
	this->ProductRemove(UPC);
	this->ProductCreate(UPC, product_name, vendor_name, price, description);
	return UPC;
}

void DatabaseConnector::ProductSearchByUPC(int UPC) {
	this->connect();
	char *zErrMsg = 0;
	std::cout << UPC << std::endl;
	std::string sql1 = "SELECT * FROM product WHERE UPC = '"+std::to_string(UPC)+"'";
	sqlite3_exec(db, sql1.c_str(), this->callback, 0, &zErrMsg);
	this->disconnect();
	// return UPC;
}

void DatabaseConnector::ProductSearchByName(std::string product_name) {
	this->connect();
	char *zErrMsg = 0;
	std::string sql1 = "SELECT * FROM product WHERE product_name = '"+product_name+"'";
	sqlite3_exec(db, sql1.c_str(), this->callback, 0, &zErrMsg);
	this->disconnect();
}

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

int DatabaseConnector::OrderUpdate(int orderid, int userid, int UPC, int quantity, int payid) {
	this->OrderRemove(orderid);
	this->OrderCreate(orderid, userid, UPC, quantity, payid);
	return orderid;
}

int DatabaseConnector::OrderRemove(int orderid) {
	this->connect();
	char *zErrMsg = 0;
	std::string sql = "DELETE FROM orders WHERE orderid = '"+std::to_string(orderid)+"'";
	sqlite3_exec(db, sql.c_str(), this->callback, 0, &zErrMsg);
	this->disconnect();
	return orderid;
}

void DatabaseConnector::OrderGetByID(int orderid) {
	this->connect();
	char *zErrMsg = 0;
	std::string sql1 = "SELECT * FROM orders WHERE orderid = '"+std::to_string(orderid)+"'";
	sqlite3_exec(db, sql1.c_str(), this->callback, 0, &zErrMsg);
	this->disconnect();
}

void DatabaseConnector::OrderSearchByUser(int userid) {
	this->connect();
	char *zErrMsg = 0;
	std::string sql1 = "SELECT * FROM orders WHERE userid = '"+std::to_string(userid)+"'";
	sqlite3_exec(db, sql1.c_str(), this->callback, 0, &zErrMsg);
	this->disconnect();
}

// payid INT PRIMARY KEY, userid, INT, method TEXT, amount REAL, refund INT
int DatabaseConnector::PaymentCreate(int payid, int userid, std::string method, std::string amount, int refund) {
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

int DatabaseConnector::PaymentUpdate(int payid, int userid, std::string method, std::string amount, int refund) {
	this->PaymentRemove(payid);
	this->PaymentCreate(payid, userid, method, amount, refund);
	return payid;
}

int DatabaseConnector::PaymentRemove(int payid) {
	this->connect();
	char *zErrMsg = 0;
	std::string sql = "DELETE FROM payment WHERE payid = '"+std::to_string(payid)+"'";
	sqlite3_exec(db, sql.c_str(), this->callback, 0, &zErrMsg);
	this->disconnect();
	return payid;
}
