#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
  public:
    // Orthodox Canonical Form
    FragTrap();
    FragTrap(const std::string &name);
    FragTrap(const FragTrap &other);
    FragTrap& operator=(const FragTrap &other);
    ~FragTrap();

    // Special ability
    void highFivesGuys(void);
};

#endif