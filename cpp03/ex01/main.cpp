#include "ScavTrap.hpp"

int main(void)
{
    std::cout << "=== Test 1: Construction/Destruction chaining ===" << std::endl;
    {
        ScavTrap scav("Guardian");
    }
    
    std::cout << "\n=== Test 2: ScavTrap attacks ===" << std::endl;
    ScavTrap scav1("Warrior");
    scav1.attack("Enemy1");
    scav1.attack("Enemy2");
    
    std::cout << "\n=== Test 3: Guard Gate ability ===" << std::endl;
    scav1.guardGate();
    
    std::cout << "\n=== Test 4: Taking damage and repairing ===" << std::endl;
    ScavTrap scav2("Tank");
    scav2.takeDamage(30);
    scav2.beRepaired(20);
    scav2.takeDamage(50);
    
    std::cout << "\n=== Test 5: Energy depletion ===" << std::endl;
    ScavTrap scav3("Exhausted");
    for (int i = 0; i < 51; i++)
        scav3.attack("Target");
    scav3.guardGate();
    
    std::cout << "\n=== Test 6: Copy constructor ===" << std::endl;
    ScavTrap scav4("Original");
    ScavTrap scav5(scav4);
    scav5.attack("CopiedTarget");
    scav5.guardGate();
    
    std::cout << "\n=== Test 7: Comparison ClapTrap vs ScavTrap ===" << std::endl;
    ClapTrap clap("Clappy");
    ScavTrap scav6("Scavvy");
    std::cout << "ClapTrap stats: HP=" << clap.getHitPoints() 
              << ", EP=" << clap.getEnergyPoints() 
              << ", AD=" << clap.getAttackDamage() << std::endl;
    std::cout << "ScavTrap stats: HP=" << scav6.getHitPoints() 
              << ", EP=" << scav6.getEnergyPoints() 
              << ", AD=" << scav6.getAttackDamage() << std::endl;
    clap.attack("Target");
    scav6.attack("Target");
    
    std::cout << "\n=== Destructors will be called ===" << std::endl;
    return 0;
}