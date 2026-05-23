#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    Bureaucrat lou("lou", 1);
    Bureaucrat daniel("daniel", 150);

    ShrubberyCreationForm form1("home");
    RobotomyRequestForm form2("R2D2");
    PresidentialPardonForm form3("Bart");

    std::cout << "--- ShrubberyCreationForm" << std::endl;
    lou.signForm(form1);
    lou.executeForm(form1);

    std::cout << "\n--- RobotomyRequestForm" << std::endl;
    daniel.signForm(form2);
    lou.signForm(form2);
    lou.executeForm(form2);
    
    std::cout << "\n--- PresidentialPardonForm" << std::endl;
    lou.signForm(form3);
    lou.executeForm(form3);
    daniel.executeForm(form3);

    return 0;
}
