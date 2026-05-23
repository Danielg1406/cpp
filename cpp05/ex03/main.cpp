#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main() {
    Intern someRandomIntern;

    std::cout << "--- Form Creation" << std::endl;

    AForm *shrubbery = someRandomIntern.makeForm("shrubbery creation", "home");
    AForm *robotomy = someRandomIntern.makeForm("robotomy request", "R2D2");
    AForm *pardon = someRandomIntern.makeForm("presidential pardon", "Bart");

    Bureaucrat boss("Boss", 1);
    Bureaucrat senior("Senior", 50);

    std::cout << std::endl;
    if (shrubbery) {
        std::cout << *shrubbery << std::endl;
        boss.signForm(*shrubbery);
        boss.executeForm(*shrubbery);
    }

    std::cout << std::endl;
    if (robotomy) {
        std::cout << *robotomy << std::endl;
        senior.signForm(*robotomy);
        boss.signForm(*robotomy);
        senior.executeForm(*robotomy);  // fails
        boss.executeForm(*robotomy); // works
    }

    std::cout << std::endl;
    if (pardon) {
        std::cout << *pardon << std::endl;
        boss.signForm(*pardon);
        boss.executeForm(*pardon);
    }

    std::cout << "\n--- Invalid Form" << std::endl;
    try {
        AForm *invalid = someRandomIntern.makeForm("coffee break", "42");
        delete invalid;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    delete shrubbery;
    delete robotomy;
    delete pardon;

    return 0;
}
