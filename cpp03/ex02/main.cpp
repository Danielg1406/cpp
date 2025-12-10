#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
    std::cout << "=== Test 1: Construction/Destruction chaining ===" << std::endl;
    {
        FragTrap frag("Destroyer");
    }
    
    std::cout << "\n=== Test 2: FragTrap attacks ===" << std::endl;
    FragTrap frag1("Warrior");
    frag1.attack("Enemy1");
    frag1.attack("Enemy2");
    
    std::cout << "\n=== Test 3: High Five ability ===" << std::endl;
    frag1.highFivesGuys();
    
    std::cout << "\n=== Test 4: Taking damage and repairing ===" << std::endl;
    FragTrap frag2("Tank");
    frag2.takeDamage(40);
    frag2.beRepaired(25);
    frag2.takeDamage(60);
    
    std::cout << "\n=== Test 5: Energy usage ===" << std::endl;
    FragTrap frag3("Energetic");
    for (int i = 0; i < 5; i++)
        frag3.attack("Target");
    frag3.highFivesGuys();
    
    std::cout << "\n=== Test 6: Copy constructor ===" << std::endl;
    FragTrap frag4("Original");
    FragTrap frag5(frag4);
    frag5.attack("CopiedTarget");
    frag5.highFivesGuys();
    
    std::cout << "\n=== Test 7: Comparison of all three types ===" << std::endl;
    ClapTrap clap("Clappy");
    ScavTrap scav("Scavvy");
    FragTrap frag6("Fraggy");
    
    std::cout << "\nClapTrap stats: HP=" << clap.getHitPoints() 
              << ", EP=" << clap.getEnergyPoints() 
              << ", AD=" << clap.getAttackDamage() << std::endl;
    std::cout << "ScavTrap stats: HP=" << scav.getHitPoints() 
              << ", EP=" << scav.getEnergyPoints() 
              << ", AD=" << scav.getAttackDamage() << std::endl;
    std::cout << "FragTrap stats: HP=" << frag6.getHitPoints() 
              << ", EP=" << frag6.getEnergyPoints() 
              << ", AD=" << frag6.getAttackDamage() << std::endl;
    
    std::cout << "\nAttacks comparison:" << std::endl;
    clap.attack("Target");
    scav.attack("Target");
    frag6.attack("Target");
    
    std::cout << "\nSpecial abilities:" << std::endl;
    scav.guardGate();
    frag6.highFivesGuys();
    
    std::cout << "\n=== Destructors will be called ===" << std::endl;
    return 0;
}