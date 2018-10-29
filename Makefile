CC=g++
CFLAGS=-Wall -std=c++14


test_logger:
	$(CC) $(CFLAGS) \
		src/tests/test_Logger_Logger.cpp \
		src/TechnicalServices/Logger/Logger.cpp \
	-o bin/test/test_logger

test_log_handler:
	$(CC) $(CFLAG) \
		src/tests/test_log_handler.cpp \
		src/TechnicalServices/Logger/Logger.cpp \
		src/Domain/LogHandler/LogHandler.cpp \
	-o bin/test/test_log_handler

test_user_handler:
	$(CC) $(CFLAG) \
		src/tests/test_userhandler.cpp \
		src/Domain/UserHandler/UserHandler.cpp \
		src/TechnicalServices/DatabaseConnector/DatabaseConnector.cpp \
	-lsqlite3 \
	-o bin/test/test_user_handler

test_order_handler:
	$(CC) $(CFLAG) \
		src/tests/test_orderhandler.cpp \
		src/Domain/OrderHandler/OrderHandler.cpp \
		src/TechnicalServices/DatabaseConnector/DatabaseConnector.cpp \
	-lsqlite3 \
	-o bin/test/test_order_handler

test_db:
	$(CC) $(CFLAGS) \
		src/tests/test_database_connector.cpp \
		src/TechnicalServices/DatabaseConnector/DatabaseConnector.cpp \
	-lsqlite3 \
	-o bin/test/test_database

test_auth:
	$(CC) $(CFLAGS) \
		src/tests/test_auth_vendor_connector.cpp \
		src/TechnicalServices/AuthorizationVendorConnector/AuthorizationVendorConnector.cpp \
	-o bin/test/test_auth_vendor_connector

test_auth_handler:
	$(CC) $(CFLAGS) \
		src/tests/test_authHandler.cpp \
		src/Domain/AuthorizationHandler/AuthorizationHandler.cpp \
		src/TechnicalServices/AuthorizationVendorConnector/AuthorizationVendorConnector.cpp \
	-o bin/test/test_auth_vendor_connector

test_tui:
	$(CC) $(CFLAGS) \
		src/tests/test_tui.cpp \
		src/UI/TextUserInterface/TextUserInterface.cpp \
		src/UI/Menu/Menu.cpp \
		src/UI/Menu/AuditorMenu.cpp \
		src/UI/Menu/AdminMenu.cpp \
		src/UI/Menu/SalespersonMenu.cpp \
		src/UI/Menu/CustomerMenu.cpp \
		src/Domain/AuthorizationHandler/AuthorizationHandler.cpp \
		src/Domain/UserHandler/UserHandler.cpp \
		src/Domain/LogHandler/LogHandler.cpp \
		src/Domain/OrderHandler/OrderHandler.cpp \
		src/TechnicalServices/AuthorizationVendorConnector/AuthorizationVendorConnector.cpp \
		src/TechnicalServices/Logger/Logger.cpp \
		src/TechnicalServices/DatabaseConnector/DatabaseConnector.cpp \
	-lsqlite3 \
	-o bin/test/test_tui

test_menu:
	$(CC) $(CFLAGS) \
		src/tests/test_menu.cpp \
		src/UI/Menu/Menu.cpp \
		src/UI/Menu/AuditorMenu.cpp \
		src/UI/Menu/AdminMenu.cpp \
		src/UI/Menu/SalespersonMenu.cpp \
		src/UI/Menu/CustomerMenu.cpp \
		src/TechnicalServices/Logger/Logger.cpp \
		src/TechnicalServices/DatabaseConnector/DatabaseConnector.cpp \
		src/Domain/UserHandler/UserHandler.cpp \
		src/Domain/LogHandler/LogHandler.cpp \
		src/Domain/OrderHandler/OrderHandler.cpp \
	-lsqlite3 \
	-o bin/test/test_menu

octodepot:
	$(CC) $(CFLAGS) \
		src/main.cpp \
		src/UI/TextUserInterface/TextUserInterface.cpp \
		src/UI/Menu/Menu.cpp \
		src/UI/Menu/AuditorMenu.cpp \
		src/UI/Menu/AdminMenu.cpp \
		src/UI/Menu/SalespersonMenu.cpp \
		src/UI/Menu/CustomerMenu.cpp \
		src/Domain/AuthorizationHandler/AuthorizationHandler.cpp \
		src/Domain/UserHandler/UserHandler.cpp \
		src/Domain/LogHandler/LogHandler.cpp \
		src/Domain/OrderHandler/OrderHandler.cpp \
		src/TechnicalServices/AuthorizationVendorConnector/AuthorizationVendorConnector.cpp \
		src/TechnicalServices/Logger/Logger.cpp \
		src/TechnicalServices/DatabaseConnector/DatabaseConnector.cpp \
	-lsqlite3 \
	-o bin/octodepot

clean:
	find bin -type f -delete
