#include "PhoneBook.hpp"

// Constructor
PhoneBook::PhoneBook() : _contactIndex(0), _contactCount(0){}

// Destructor
PhoneBook::~PhoneBook() {}

// Commands
void PhoneBook::addContact()
{
  int currentIndex = getContactIndex();
  int totalContact = getContactCount();
  
  std::string firstName = getValidInput("Enter first name: ", false);
  std::string lastName = getValidInput("Enter last name: ", false);
  std::string nickname = getValidInput("Enter nickname: ", false);
  std::string phoneNumber = getValidInput("Enter phone number: ", true);
  std::string darkestSecret = getValidInput("Enter darkest secret: ", false);

  Contact newContact(firstName, lastName, nickname, phoneNumber, darkestSecret);
  _contactList[currentIndex] = newContact;
  
  if (totalContact < MAX_CONTACT_AMOUNT)
    setContactCount();
  
  setContactIndex(INCREMENT);
  std::cout << "Contact successfully saved" << std::endl;
}

void PhoneBook::searchContact()
{
  
  int totalCount = getContactCount();
  if (totalCount == 0)
  {
    std::cout << "Currently there are no contacts to display" << std::endl;
    return;
  }

  displayHeader();
  for (int i = 0; i < totalCount; i++)
  {
    std::cout << std::setw(COLUMN_WIDTH) << i + 1 << "|";
    std::cout << std::setw(COLUMN_WIDTH) << truncateInput(_contactList[i].getFirstName()) << "|";
    std::cout << std::setw(COLUMN_WIDTH) << truncateInput(_contactList[i].getLastName()) << "|";
    std::cout << std::setw(COLUMN_WIDTH) << truncateInput(_contactList[i].getNickname()) << std::endl;
  }
  
  std::cout << "Enter the index of the contact to see full details: ";
  std::string input;
  if (!std::getline(std::cin, input))
  {
    std::cout << std::endl;
    exit(0);
  }
  
  int index;
  if (!strToInt(input, index))
  {
    std::cerr << "Invalid index" << std::endl;
    return;
  }

  if (index < 1 || index > totalCount)
  {
    std::cerr << "Index out of range" << std::endl;
    return;
  }

  std::cout << "First Name: " << _contactList[index - 1].getFirstName() << std::endl;
  std::cout << "Last Name: " << _contactList[index - 1].getLastName() << std::endl;
  std::cout << "Nickname: " << _contactList[index - 1].getNickname() << std::endl; 
  std::cout << "Phone Number: " << _contactList[index - 1].getPhoneNumber() << std::endl;
  std::cout << "Darkest Secret: " << _contactList[index - 1].getDarkestSecret() << std::endl;
}

// Getters
int PhoneBook::getContactIndex()
{
  return _contactIndex;
}

int PhoneBook::getContactCount()
{
  return _contactCount;
}

// Setters
void PhoneBook::setContactIndex(IndexOption option)
{
  if (option == RESET)
    _contactIndex = 0;
  else
    _contactIndex = (_contactIndex + 1) % MAX_CONTACT_AMOUNT;
}

void PhoneBook::setContactCount()
{
  _contactCount++;
}