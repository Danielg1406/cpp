#include <iostream>
#include <string>

int main(int argc, char **argv)
{
  if (argc == 1)
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
  else
  {
    for (int i = 1; i < argc; i++)
    {
      if (i > 1)
        std::cout << " ";
      std::string arg = argv[i];
      for (char c : arg)
        std::cout << (char)std::toupper(c);
    }
  }
  std::cout << std::endl;
  return 0;
}