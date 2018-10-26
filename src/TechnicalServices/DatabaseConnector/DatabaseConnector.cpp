#include "DatabaseConnector.hpp"
#include <sqlite3.h>

DatabaseConnector::DatabaseConnector() {
	// TODO - implement DatabaseConnector::DatabaseConnector
	throw "Not yet implemented";
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
