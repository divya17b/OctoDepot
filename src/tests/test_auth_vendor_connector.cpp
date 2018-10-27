#include <string>
#include <iostream>
#include "../TechnicalServices/AuthorizationVendorConnector/AuthorizationVendorConnector.hpp"

int main() {
    int score = 0;

    std::cout << "Test for TechnicalServices/AuthorizationVendorConnector" << std::endl;
    // initialize class
    std::cout << "  1. initialize class";
    AuthorizationVendorConnector auth("auth.vendor.com/api/v15/");
    std::cout << "- Success" << std::endl;

    std::cout << "  2. authenticate user admin";
    int permission = auth.authenticateUser(1, "qwer1234asdf");
    if ( permission == 0 )
        std::cout << "- Success" << std::endl;
    else {
        score += 1;
        std::cout << "- Fail" << std::endl;
    }

    std::cout << "  3. authenticate user manager";
    permission = auth.authenticateUser(100, "qwer1234asdf");
    if ( permission == 100 )
        std::cout << "- Success" << std::endl;
    else {
        score += 1;
        std::cout << "- Fail" << std::endl;
    }

    std::cout << "  4. authenticate user auditor";
    permission = auth.authenticateUser(200, "qwer1234asdf");
    if ( permission == 200 )
        std::cout << "- Success" << std::endl;
    else {
        score += 1;
        std::cout << "- Fail" << std::endl;
    }

    std::cout << "  5. authenticate user customer";
    permission = auth.authenticateUser(1000, "qwer1234asdf");
    if ( permission == 1000 )
        std::cout << "- Success" << std::endl;
    else {
        score += 1;
        std::cout << "- Fail" << std::endl;
    }

    if (!score) {
        std::cout << "All Test Cases Passed!" << std::endl;
    }
}