#include "Zombie.hpp"

int main(void)
{
  int horde_size = 5;
  std::cout << "Let the war Z begin..." << std::endl;
  Zombie* war_Z = zombieHorde(horde_size, "Walker");

  std::cout << "\nZombies announcing:" << std::endl;
  for (int i = 0; i < horde_size; i++)
    war_Z[i].announce();

  delete[] war_Z;
  std::cout << "Brad Pitt did it again" << std::endl;
  return 0;
}