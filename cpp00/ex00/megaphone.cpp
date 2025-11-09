#include <iostream>
#include <string>
#include <cctype>

std::string str_toupper(std::string str)
{
  for (size_t i = 0; i < str.length(); i++)
    str[i] = static_cast<char>(std::toupper(static_cast<unsigned char>(str[i])));
  return str;
}

int main(int argc, char **argv)
{
  if (argc == 1)
  {
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    return (1);
  }
  for (int i = 1; i < argc; i++)
    {
      std::string upper_str = str_toupper(argv[i]);
      if (i > 1)
        std::cout << " ";
      std::cout << upper_str;
    }
  std::cout << std::endl;
  return (0);
}

