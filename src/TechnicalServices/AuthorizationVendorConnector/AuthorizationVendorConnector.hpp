#ifndef AuthorizationVendorConnector_HPP
#define AuthorizationVendorConnector_HPP

class AuthorizationVendorConnector {
private:
    std::string api;

public:
	AuthorizationVendorConnector(std::string url);
	int authenticateUser(int UserID, std::string password);
};

#endif