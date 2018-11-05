#include <string>
#include "AuthorizationVendorConnector.hpp"

AuthorizationVendorConnector::AuthorizationVendorConnector(std::string url) {
    api = url;
}
AuthorizationVendorConnector::~AuthorizationVendorConnector() {}

// for the prototype, the purpose is demo. so mock up the api
int AuthorizationVendorConnector::authenticateUser(int UserID, std::string password) {
	if (UserID == 1 && !(password.compare("qwer1234")) ) {
        return 0;
    }
    else if (UserID == 100 && !(password.compare("qwer1234")) ) {
        return 100;
    }
    else if (UserID == 200 && !(password.compare("qwer1234")) ) {
        return 200;
    }
    else if (UserID == 1000 && !(password.compare("qwer1234")) ) {
        return 1000;
    }
    else if (UserID == 1001 && !(password.compare("A904#!^wWcIDRL%^rp&Tv%@QIjOWYYk$14i")) ) {
        return 0;
    }
    else if (UserID == 2001 && !(password.compare("$Fak%iXH%s@8PtA$WOjA")) ) {
        return 100;
    }
    else if (UserID == 3001 && !(password.compare("Rvzm4#PfX0t2rzE$tJs1")) ) {
        return 200;
    }
    else if (UserID == 647238 && !(password.compare("vZeI0Jd#!9#NtPbEe3Yn")) ) {
        return 1000;
    }
    else if (UserID == 837502 && !(password.compare("!hM%41g*OyYs^G^utGEh")) ) {
        return 1000;
    }
    else if (UserID == 726941 && !(password.compare("FpIp&%8bWAqQmaw$UAAz")) ) {
        return 1000;
    }
    return -1;
}