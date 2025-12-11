#include "PhoneBook.hpp"

int main(void)
{
  PhoneBook myPhonebook;
  std::string option;
  
  while (true)
  {
    std::cout << "Enter an option - ADD, SEARCH, or EXIT" << std::endl;
    if (!std::getline(std::cin, option))
    {
      std::cout << std::endl;
      break;
    }
    if (option == "ADD")
      myPhonebook.addContact();
    else if (option == "SEARCH")
      myPhonebook.searchContact();
    else if (option == "EXIT")
      break;
    else
      std::cout << "Invalid option" << std::endl;
  }
  return 0;
}