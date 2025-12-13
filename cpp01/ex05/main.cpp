#include "Harl.hpp"

int main(void)
{
  Harl karen;

  std::cout << "---- Testing DEBUG ----" << std::endl;
  karen.complain("DEBUG");
  std::cout << std::endl;

  std::cout << "---- Testing INFO ----" << std::endl;
  karen.complain("INFO");
  std::cout << std::endl;

  std::cout << "---- Testing WARNING ----" << std::endl;
  karen.complain("WARNING");
  std::cout << std::endl;

  std::cout << "---- Testing ERROR ----" << std::endl;
  karen.complain("ERROR");
  std::cout << std::endl;

  std::cout << "---- Testing Invalid Level ----" << std::endl;
  karen.complain("INVALID");

  return 0;
}