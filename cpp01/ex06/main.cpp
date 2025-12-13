#include "Harl.hpp"

int main(int argc, char **argv)
{
  if (argc != 2)
  {
    std::cerr << "Error! Invalid amount of parameters" << std::endl;
    return 1;
  }
  Harl karen;
  karen.complain(argv[1]);
  return 0;
}