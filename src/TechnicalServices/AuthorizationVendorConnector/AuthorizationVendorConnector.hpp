#ifndef AuthorizationVendorConnector_HPP
#define AuthorizationVendorConnector_HPP

class AuthorizationVendorConnector {
private:
	// the url of the API in string
    std::string api;

public:
	AuthorizationVendorConnector(std::string url);
	// contact API to verify the UserID/password combination
	// acquire permission of the UserID
	int authenticateUser(int UserID, std::string password);
};

#endif