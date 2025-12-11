#include "Contact.hpp"

// Constructors
Contact::Contact() {}

Contact::Contact(
      const std::string &firstName,
      const std::string &lastName,
      const std::string &nickname,
      const std::string &phoneNumber,
      const std::string &darkestSecret
    ) :
    _firstName(firstName),
    _lastName(lastName),
    _nickname(nickname),
    _phoneNumber(phoneNumber),
    _darkestSecret(darkestSecret)
    {}

// Destructor
Contact::~Contact(){}
    
// Getters
std::string Contact::getFirstName() const
{
  return _firstName;
}

std::string Contact::getLastName() const
{
  return _lastName;
}

std::string Contact::getNickname() const
{
  return _nickname;
}

std::string Contact::getPhoneNumber() const
{
  return _phoneNumber;
}

std::string Contact::getDarkestSecret() const
{
  return _darkestSecret;
}