#include "ClapTrap.hpp"

int main(void)
{
    std::cout << "=== Test 1: Basic attacks ===" << std::endl;
    ClapTrap clap1("Clappy");
    clap1.attack("Target1");
    clap1.attack("Target2");
    
    std::cout << "\n=== Test 2: Taking damage ===" << std::endl;
    ClapTrap clap2("Damaged");
    clap2.takeDamage(3);
    clap2.takeDamage(5);
    clap2.takeDamage(10);
    clap2.attack("Someone");
    
    std::cout << "\n=== Test 3: Repairing ===" << std::endl;
    ClapTrap clap3("Healer");
    clap3.takeDamage(5);
    clap3.beRepaired(3);
    clap3.beRepaired(10);
    
    std::cout << "\n=== Test 4: Energy depletion ===" << std::endl;
    ClapTrap clap4("Tired");
    for (int i = 0; i < 11; i++)
        clap4.attack("Enemy");
    clap4.beRepaired(5);
    
    std::cout << "\n=== Test 5: Copy constructor ===" << std::endl;
    ClapTrap clap5("Original");
    ClapTrap clap6(clap5);
    clap6.attack("Target");
    
    std::cout << "\n=== Destructors will be called ===" << std::endl;
    return 0;
}