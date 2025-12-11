#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <cstdlib>
#include <sstream>

// Constructor
PhoneBook::PhoneBook() : _contact_index(0), _contact_count(0){}

// Destructor
PhoneBook::~PhoneBook() {}

// Utils
std::string truncateInput(std::string input)
{
  if (input.length() > COLUMN_WIDTH)
    return input.substr(0, COLUMN_WIDTH - 1) + ".";
  return input;
}

std::string getValidInput(const std::string &prompt)
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
        return input;
    }
    std::cout << "Field cannot be empty. Please try again." << std::endl;
  }
}

// Commands
void PhoneBook::addContact()
{
  int current_index = getContactIndex();
  int total_contact = getContactCount();
  std::string first_name;
  std::string last_name;
  std::string nickname;
  std::string phone_number;
  std::string darkest_secret;

  first_name = getValidInput("Enter first name: ");
  last_name = getValidInput("Enter last name: ");
  nickname = getValidInput("Enter nickname: ");
  phone_number = getValidInput("Enter phone number: ");
  darkest_secret = getValidInput("Enter darkest secret: ");

  Contact new_contact(first_name, last_name, nickname, phone_number, darkest_secret);
  if (total_contact < MAX_CONTACT_AMOUNT)
  {
    _contact_list[current_index] = new_contact;
    setContactCount();
  }
  else
  {
    setContactIndex(RESET);
    _contact_list[0] = new_contact;
  }
  setContactIndex(INCREMENT);
  std::cout << "Contact successfully saved" << std::endl;
}

void PhoneBook::searchContact()
{
  int total_count = getContactCount();

  if (total_count == 0)
  {
    std::cout << "Currently there are no contacts to display" << std::endl;
    return;
  }

  std::string input;
  int id;
 
  std::cout << std::setw(COLUMN_WIDTH) << "INDEX" << "|";
  std::cout << std::setw(COLUMN_WIDTH) << "FIRST NAME" << "|";
  std::cout << std::setw(COLUMN_WIDTH) << "LAST NAME" << "|";
  std::cout << std::setw(COLUMN_WIDTH) << "NICKNAME" << std::endl;
  for (int i = 0; i < total_count; i++)
  {
    std::cout << std::setw(COLUMN_WIDTH) << i + 1 << "|";
    std::cout << std::setw(COLUMN_WIDTH) << truncateInput(_contact_list[i].getFirstName()) << "|";
    std::cout << std::setw(COLUMN_WIDTH) << truncateInput(_contact_list[i].getLastName()) << "|";
    std::cout << std::setw(COLUMN_WIDTH) << truncateInput(_contact_list[i].getNickname()) << std::endl;
  }

  std::cout << "Enter the index of the contact to see full details: ";
  if (!std::getline(std::cin, input))
  {
    std::cout << std::endl;
    exit(0);
  }

  std::stringstream ss(input);
  // The >> operator fails if input starts with non-digits
  // The eof() check ensures no extra characters remain after the number
  if (!(ss >> id) || !(ss.eof()))
  {
    std::cout << "Invalid index" << std::endl;
    return;
  }

  if (id < 1 || id > total_count)
  {
    std::cout << "Index out of range" << std::endl;
    return;
  }

  std::cout << "First Name: " << _contact_list[id - 1].getFirstName() << std::endl;
  std::cout << "Last Name: " << _contact_list[id - 1].getLastName() << std::endl;
  std::cout << "Nickname: " << _contact_list[id - 1].getNickname() << std::endl; 
  std::cout << "Phone Number: " << _contact_list[id - 1].getPhoneNumber() << std::endl;
  std::cout << "Darkest Secret: " << _contact_list[id - 1].getDarkestSecret() << std::endl;
}

// Getters
int PhoneBook::getContactIndex()
{
  return _contact_index;
}

int PhoneBook::getContactCount()
{
  return _contact_count;
}

// Setters
void PhoneBook::setContactIndex(IndexOption option)
{
  if (option == RESET)
    _contact_index = 0;
  else
    _contact_index++;
}

void PhoneBook::setContactCount()
{
  _contact_count++;
}