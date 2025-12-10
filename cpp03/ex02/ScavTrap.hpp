#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
  public:
    // Orthodox Canonical Form
    ScavTrap();
    ScavTrap(const std::string &name);
    ScavTrap(const ScavTrap &other);
    ScavTrap& operator=(const ScavTrap &other);
    ~ScavTrap();

    // Override attack function
    void attack(const std::string& target);

    // Special ability
    void guardGate();
};

#endif