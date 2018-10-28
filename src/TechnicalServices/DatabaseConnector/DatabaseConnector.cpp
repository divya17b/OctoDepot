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
	const char *sql0 = "DROP TABLE user";
	const char *sql1 = "CREATE TABLE user (userid INT PRIMARY KEY, company_name VARCHAR(255), contact_name VARCHAR(30), address VARCHAR(255), email VARCHAR(255), phone VARCHAR(30))";
	// const char *sql2 = "create table myTable (UPC int PRIMARY KEY, name varchar(30))";
	// const char *sql3 = "create table myTable (UPC int PRIMARY KEY, name varchar(30))";
	sqlite3_exec(db, sql0, this->callback, 0, &zErrMsg);
	sqlite3_exec(db, sql1, this->callback, 0, &zErrMsg);
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
	return 0;
}


void DatabaseConnector::ProductCreate(int productID, int productName, int productPrice, int UPC, int description) {
	// TODO - implement DatabaseConnector::ProductCreate
	throw "Not yet implemented";
}

void DatabaseConnector::ProductUpdate(int productID, int productName, int productPrice, int UPC, int description) {
	// TODO - implement DatabaseConnector::ProductUpdate
	throw "Not yet implemented";
}

void DatabaseConnector::ProductGetByID(int productID) {
	// TODO - implement DatabaseConnector::ProductGetByID
	throw "Not yet implemented";
}

void DatabaseConnector::ProductSearchByUPC(int UPC) {
	// TODO - implement DatabaseConnector::ProductSearchByUPC
	throw "Not yet implemented";
}

void DatabaseConnector::ProductSearchByName(int productName) {
	// TODO - implement DatabaseConnector::ProductSearchByName
	throw "Not yet implemented";
}

void DatabaseConnector::OrderCreate(int orderID, int productID, int userID, int quantity, int paymentID) {
	// TODO - implement DatabaseConnector::OrderCreate
	throw "Not yet implemented";
}

void DatabaseConnector::OrderUpdate(int orderID, int productID, int userID, int quantity, int paymentID) {
	// TODO - implement DatabaseConnector::OrderUpdate
	throw "Not yet implemented";
}

void DatabaseConnector::OrderRemove(int orderID) {
	// TODO - implement DatabaseConnector::OrderRemove
	throw "Not yet implemented";
}

void DatabaseConnector::OrderGetByID(int orderID) {
	// TODO - implement DatabaseConnector::OrderGetByID
	throw "Not yet implemented";
}

void DatabaseConnector::OrderSearchByUser(int userid) {
	// TODO - implement DatabaseConnector::OrderSearchByUser
	throw "Not yet implemented";
}

void DatabaseConnector::PaymentCreate(int paymentID) {
	// TODO - implement DatabaseConnector::PaymentCreate
	throw "Not yet implemented";
}

void DatabaseConnector::PaymentCreate(int paymentID, int paymentStatus) {
	// TODO - implement DatabaseConnector::PaymentCreate
	throw "Not yet implemented";
}

void DatabaseConnector::PaymentUpdate(int paymentID, int paymentStatus) {
	// TODO - implement DatabaseConnector::PaymentUpdate
	throw "Not yet implemented";
}

void DatabaseConnector::PaymentRemove(int paymentID) {
	// TODO - implement DatabaseConnector::PaymentRemove
	throw "Not yet implemented";
}
