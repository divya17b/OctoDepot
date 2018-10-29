#include <string>
#include "../UI/Menu/Menu.hpp"
#include "../UI/Menu/AuditorMenu.hpp"
#include "../UI/Menu/AdminMenu.hpp"
#include "../UI/Menu/SalespersonMenu.hpp"
#include "../UI/Menu/CustomerMenu.hpp"

int main() {
    Menu m;
    m.sessionLoop();

    AuditorMenu auditorMenu(1234567);
    auditorMenu.sessionLoop();

    AdminMenu adminMenu(1234567);
    adminMenu.sessionLoop();

    CustomerMenu customerMenu(1234567);
    customerMenu.sessionLoop();

    SalespersonMenu salesMenu(1234567);
    salesMenu.sessionLoop();

    return 0;
}