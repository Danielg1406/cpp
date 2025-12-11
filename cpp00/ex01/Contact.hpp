#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
  private:
    std::string _firstName;
    std::string _lastName;
    std::string _nickname;
    std::string _phoneNumber;
    std::string _darkestSecret;

  public:
    // Default Constructor
    Contact();

    // Parameterized Constructor
    Contact(
      const std::string &firstName,
      const std::string &lastName,
      const std::string &nickname,
      const std::string &phoneNumber,
      const std::string &darkestSecret
    );

    // Destructor
    ~Contact();
    
    // Getters
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getNickname() const;
    std::string getPhoneNumber() const;
    std::string getDarkestSecret() const;
};

#endif