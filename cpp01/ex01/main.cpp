#include "Zombie.hpp"

int main(void)
{
  int hordeSize = 5;
  std::cout << "Let the war Z begin..." << std::endl;
  Zombie *warZ = zombieHorde(hordeSize, "Walker");

  std::cout << "\nZombies announcing:" << std::endl;
  for (int i = 0; i < hordeSize; i++)
    warZ[i].announce();

  delete[] warZ;
  std::cout << "Brad Pitt did it again" << std::endl;
  return 0;
}