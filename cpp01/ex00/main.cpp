#include "Zombie.hpp"

int main(void)
{
  Zombie* heap_zombie = newZombie("Zombie in the Heap");
  heap_zombie->announce();

  // Stack allocation - dies when out of scope
  randomChump("Zombie in the Stack");

  // Heap allocation must be manually deleted
  delete heap_zombie;
  std::cout << "No memory leaking Zombie left :)" << std::endl;
  return 0;
}