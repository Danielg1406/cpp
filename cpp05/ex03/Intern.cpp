#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

// Canonical Form
Intern::Intern() {}

Intern::Intern(const Intern &other)
{
    (void)other;
}

Intern &Intern::operator=(const Intern &other)
{
    (void)other;
    return *this;
}

Intern::~Intern() {}

// Create Forms
AForm* Intern::createShrub(const std::string &target) const {
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobot(const std::string &target) const {
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPardon(const std::string &target) const {
    return new PresidentialPardonForm(target);
}

// Make Form
AForm* Intern::makeForm(const std::string &name, const std::string &target) const {
    const std::string names[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    AForm* (Intern::*creators[3])(const std::string &) const = { &Intern::createShrub, &Intern::createRobot, &Intern::createPardon };

    for (int i = 0; i < 3; ++i) {
        if (name == names[i]) {
            AForm *form = (this->*creators[i])(target);
            std::cout << "Intern creates " << names[i] << std::endl;
            return form;
        }
    }
    std::cout << "Intern couldn't create form: unknown form name\n";
    return NULL;
}
