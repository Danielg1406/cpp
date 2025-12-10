#include "Harl.hpp"

int main(void)
{
    Harl harl;

    std::cout << "---- Testing levels ----" << std::endl;
    std::cout << std::endl;

    harl.complain("DEBUG");
    harl.complain("INFO");
    harl.complain("WARNING");
    harl.complain("ERROR");

    std::cout << "=== Testing invalid level ===" << std::endl;
    std::cout << std::endl;
    harl.complain("INVALID");

    std::cout << "=== Testing random order ===" << std::endl;
    std::cout << std::endl;
    harl.complain("ERROR");
    harl.complain("DEBUG");
    harl.complain("WARNING");

    return 0;
}