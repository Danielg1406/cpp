#include "Bureaucrat.hpp"

#include "Form.hpp"

// Exception Message
const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade too low!";
}

// Canonical Form
Bureaucrat::Bureaucrat(): _name("New"), _grade(150){}

Bureaucrat::Bureaucrat(const std::string &name, int grade): _name(name) {
	if (grade > 150)
		throw GradeTooLowException();
	if (grade < 1)
		throw GradeTooHighException();
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other): _name(other._name), _grade(other._grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other) {
	if (this != &other)
		this->_grade = other.getGrade();
	return *this;
}

Bureaucrat::~Bureaucrat() {}

// Getters
const std::string	&Bureaucrat::getName() const{
	return this->_name;
}

int		Bureaucrat::getGrade() const{
	return this->_grade;
}

// Setters
void		Bureaucrat::incrementGrade() {
	if (this->_grade - 1 < 1)
		throw GradeTooHighException();
	this->_grade--;
}

void		Bureaucrat::decrementGrade() {
	if (this->_grade + 1 > 150)
		throw GradeTooLowException();
	this->_grade++;
}

void		Bureaucrat::signForm(Form &form) {
	try {
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	} catch (std::exception &e) {
		std::cout << this->getName() << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

// Operator Overload
std::ostream&	operator<<(std::ostream &out, const Bureaucrat &bureaucrat) {
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return out;
}