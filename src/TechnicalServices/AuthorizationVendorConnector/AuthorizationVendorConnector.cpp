#include <string>
#include "AuthorizationVendorConnector.hpp"

AuthorizationVendorConnector::AuthorizationVendorConnector(std::string url) {
    api = url;
}

// for the prototype, the purpose is demo. so mock up the api
int AuthorizationVendorConnector::authenticateUser(int UserID, std::string password) {
	if (UserID == 1 && !(password.compare("qwer1234asdf")) ) {
        return 0;
    }
    if (UserID == 100 && !(password.compare("qwer1234asdf")) ) {
        return 100;
    }
    if (UserID == 200 && !(password.compare("qwer1234asdf")) ) {
        return 200;
    }
    if (UserID == 1000 && !(password.compare("qwer1234asdf")) ) {
        return 1000;
    }
    return -1;
}