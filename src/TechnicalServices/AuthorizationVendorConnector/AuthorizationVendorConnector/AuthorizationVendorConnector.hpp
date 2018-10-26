#ifndef AUTHVENDORCONNECTOR_HPP
#define AUTHVENDORCONNECTOR_HPP

class AuthVendorConnector {


public:
	AuthVendorConnector(int api);
    AuthVendorConnector(int api, int username, int password);
	int authenticateUser(int username, int password);
};

#endif