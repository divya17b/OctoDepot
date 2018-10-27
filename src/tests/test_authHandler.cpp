#include <string>
#include <iostream>
#include "../Domain/AuthorizationHandler/AuthorizationHandler.hpp"
// #include "../TechnicalServices/AuthorizationVendorConnector/AuthorizationVendorConnector.hpp"

int main() {
    AuthorizationHandler authHandler;
    int result = authHandler.authenticate(1, "qwer1234asdf");
    std::cout << result <<std::endl;
}