# ifndef INTERN_HPP
# define INTERN_HPP

#include <string>
#include "AForm.hpp"

class Intern
{
    private:
        AForm* createShrub(const std::string &target) const;
        AForm* createRobot(const std::string &target) const;
        AForm* createPardon(const std::string &target) const;
    public:
        Intern();
        Intern(const Intern &other);
        Intern &operator=(const Intern &other);
        ~Intern();

        AForm* makeForm(const std::string &name, const std::string &target) const;

        class InvalidFormException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
};

#endif