#include "Zombie.hpp"

int main(void)
{
  std::cout << "Creating Zombie in Heap" << std::endl;
  Zombie *heapZombie = newZombie("Heap Zombie");
  heapZombie->announce();

  std::cout << "Creating Zombie in Stack" << std::endl;
  randomChump("Stack Zombie");

  std::cout << "It's time to free some space in Heap" << std::endl;
  delete heapZombie;
  std::cout << "No memory leaking Zombie left :)" << std::endl;
  return 0;
}