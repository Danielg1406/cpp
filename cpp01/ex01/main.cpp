#include "Zombie.hpp"

int main(void)
{
  std::cout << "let the War Z begin..." << std::endl;
  int hordeSize = 4;
  Zombie *warZ = zombieHorde(hordeSize, "Walker");
  for (int i = 0; i < hordeSize; i++)
    warZ[i].announce();

  std::cout << "Our heroe has arrived" << std::endl;
  delete[] warZ;
  std::cout << "Brad Pitt did it again!" << std::endl;

  return 0;
}