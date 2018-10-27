CC=g++
CFLAGS=-Wall -std=c++14

# hello: src/hello/hello.cpp
# 	$(CC) $(CFLAGS) src/hello/hello.cpp -o bin/hello
#
# oop_hello:
# 	$(CC) $(CFLAGS) -c src/oop_hello/oop_hello.cpp -o bin/oop_hello.o
# 	$(CC) $(CFLAGS) -c -fPIC src/oop_hello/speak/speak.cpp -o bin/shared/speak.o
# 	$(CC) $(CFLAGS) -shared bin/shared/speak.o -o bin/shared/libspeak.so
# 	$(CC) $(CFLAGS) bin/oop_hello.o -Lbin/shared -lspeak -o bin/oop_hello

test_logger:
	$(CC) $(CFLAGS) src/tests/test_Logger_Logger.cpp src/TechnicalServices/Logger/Logger.cpp -o bin/test/test_logger

test_db:
	$(CC) $(CFLAGS) src/tests/test_database_connector.cpp src/TechnicalServices/DatabaseConnector/DatabaseConnector.cpp -lsqlite3 -o bin/test/test_database

test_auth:
	$(CC) $(CFLAGS) src/tests/test_auth_vendor_connector.cpp src/TechnicalServices/AuthorizationVendorConnector/AuthorizationVendorConnector.cpp -o bin/test/test_auth_vendor_connector

clean:
	find bin -type f -delete
