#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
  private:
    std::string _first_name;
    std::string _last_name;
    std::string _nickname;
    std::string _phone_number;
    std::string _darkest_secret;

  public:
    Contact();
    // Parameterized Constructor
    Contact(
      const std::string &first_name,
      const std::string &last_name,
      const std::string &nickname,
      const std::string &phone_number,
      const std::string &darkest_secret
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