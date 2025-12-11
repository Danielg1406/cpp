#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#define MAX_CONTACT_AMOUNT 8
#define COLUMN_WIDTH 10

#include "Contact.hpp"
#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <sstream>
#include <climits>

enum IndexOption {
  INCREMENT,
  RESET
};

class PhoneBook {
  private:
    Contact _contactList[MAX_CONTACT_AMOUNT];
    int _contactIndex;
    int _contactCount;

  public:
    // Constructor
    PhoneBook();
    // Destructor
    ~PhoneBook();

    // Commands
    void addContact();
    void searchContact();

    // Getters
    int getContactIndex();
    int getContactCount();

    // Setters
    void setContactIndex(IndexOption option);
    void setContactCount();
};

// Utils
std::string getValidInput(const std::string &prompt, bool isPhoneNumber);
std::string truncateInput(const std::string &input);
bool validNumber(const std::string &input);
void displayHeader();
bool strToInt(const std::string &str, int &num);

#endif