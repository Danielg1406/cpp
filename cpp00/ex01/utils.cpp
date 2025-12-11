#include "PhoneBook.hpp"

std::string getValidInput(const std::string &prompt, bool isPhoneNumber)
{
  std::string input;
  
  while (true)
  {
    std::cout << prompt;
    if (!std::getline(std::cin, input))
    {
      std::cout << std::endl;
      exit(0);
    }
    // Remove leading/trailing whitespace
    size_t start = input.find_first_not_of(" \t\n\r");
    size_t end = input.find_last_not_of(" \t\n\r");
    
    if (start != std::string::npos && end != std::string::npos)
    {
      input = input.substr(start, end - start + 1);
      if (!input.empty())
      {
        if (isPhoneNumber)
        {
          if (validNumber(input))
            return input;
          else
          {
            std::cerr << "It must contain only digits. Please try again." << std::endl;
            continue;
          }
        }
        else
          return input;
      }
    }
    std::cerr << "Field cannot be empty. Please try again." << std::endl;
  }
}

std::string truncateInput(const std::string &input)
{
  if (input.length() > COLUMN_WIDTH)
    return input.substr(0, COLUMN_WIDTH - 1) + ".";
  return input;
}


void displayHeader()
{
  std::cout << std::setw(COLUMN_WIDTH) << "INDEX" << "|";
  std::cout << std::setw(COLUMN_WIDTH) << "FIRST NAME" << "|";
  std::cout << std::setw(COLUMN_WIDTH) << "LAST NAME" << "|";
  std::cout << std::setw(COLUMN_WIDTH) << "NICKNAME" << std::endl;
}

bool validNumber(const std::string &input)
{
  int phoneNumber;
  if (strToInt(input, phoneNumber))
    if (phoneNumber > 0 && phoneNumber <= INT_MAX)
      return true;
  return false;
}

bool strToInt(const std::string &str, int &num)
{
  std::stringstream ss(str);
  ss >> num;
  if (ss.fail() || !ss.eof())
    return false;
  return true;
}