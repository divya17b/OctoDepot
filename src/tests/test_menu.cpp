#include <string>
#include "../UI/Menu/Menu.hpp"
#include "../UI/Menu/AuditorMenu.hpp"
#include "../UI/Menu/AdminMenu.hpp"
#include "../UI/Menu/SalespersonMenu.hpp"
#include "../UI/Menu/CustomerMenu.hpp"

int main() {
    Menu m;
    m.sessionLoop();

    AuditorMenu auditorM;
    auditorM.sessionLoop();

    AdminMenu adminMenu;
    adminMenu.sessionLoop();

    CustomerMenu customerMenu;
    customerMenu.sessionLoop();

    SalespersonMenu salesMenu;
    salesMenu.sessionLoop();

    return 0;
}