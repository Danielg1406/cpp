#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#define MAX_CONTACT_AMOUNT 8
#define COLUMN_WIDTH 10

#include "Contact.hpp"
#include <iostream>
#include <string>
#include <iomanip>

enum IndexOption {
  INCREMENT,
  RESET
};

class PhoneBook {
  private:
    Contact _contact_list[8];
    int _contact_index;
    int _contact_count;

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

std::string getValidInput(const std::string &prompt);

#endif