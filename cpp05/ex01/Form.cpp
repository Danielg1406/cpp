#include "Form.hpp"
#include "Bureaucrat.hpp"

// Exception Message
const char* Form::GradeTooHighException::what() const throw() {
	return "Grade too high!";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "Grade too low!";
}

// Canonical Form
Form::Form (const std::string &name, const int gradeToSign, const int gradeToExecute): _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
}

Form::Form(const Form &other)
	: _name(other._name)
	, _isSigned(other._isSigned)
	, _gradeToSign(other._gradeToSign)
	, _gradeToExecute(other._gradeToExecute)
{}

Form& Form::operator=(const Form &other) {
	if (this != &other)
		_isSigned = other.getStatus();
	return *this;
}

Form::~Form() {}

// Actions
void	Form::beSigned(const Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw GradeTooLowException();
	this->_isSigned = true;
}

// Getters
const std::string	&Form::getName() const {
	return this->_name;
}

bool		Form::getStatus() const {
	return this->_isSigned;
}

int		Form::getGradeToSign() const {
	return this->_gradeToSign;
}

int		Form::getGradeToExecute() const {
	return this->_gradeToExecute;
}

// Operator Overload
std::ostream&	operator<<(std::ostream &out, const Form &form) {
	out << "Form \"" << form.getName() << "\" (signed: " << (form.getStatus() ? "yes" : "no") << ") -- grade to sign: "
		<< form.getGradeToSign() << ", grade to execute: " << form.getGradeToExecute();
	return out;
}
