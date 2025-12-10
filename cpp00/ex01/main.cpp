#include "PhoneBook.hpp"

int main(void)
{
  PhoneBook my_phonebook;
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
      my_phonebook.addContact();
    else if (option == "SEARCH")
      my_phonebook.searchContact();
    else if (option == "EXIT")
      break;
    else
      std::cout << "Invalid option" << std::endl;
  }
  return (0);
}