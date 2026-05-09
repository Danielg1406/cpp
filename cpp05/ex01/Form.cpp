#include "Form.hpp"
#include "Bureaucrat.hpp"

// Exception Message
const char* Form::GradeTooHighException::what() const throw() {
   return "Grade too high!\n";
}

const char* Form::GradeTooLowException::what() const throw() {
   return "Grade too low!\n";
}

// Canonical Form
Form::Form (const std::string &name, const int gradeToSign, const int gradeToExecute): _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
//	this->_gradeToSign = gradeToSign;
//	this->_gradeToExecute = gradeToExecute;
}

Form::Form(const Form &other)
	: _name(other._name)
	, _isSigned(other._isSigned)
	, _gradeToSign(other._gradeToSign)
	, _gradeToExecute(other._gradeToExecute)
{}

Form& Form::operator=(const Form &other) {
	if (this != &other)
	{
		_isSigned = other.getStatus();
		_gradeToSign = other.getGradeToSign();
		_gradeToExecute = other.getGradeToExecute();
	}
	return *this;
}

Form::~Form() {}

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

// Setters


// Operator Overload
std::ostream&	operator<<(std::ostream &out, const Form form) {
	if (form.getStatus())
	{
		std::string status = " is signed";
		out << form.getName() << status << ".Required grade to be executed: " << form.getGradeToExecute();
	}
	else
	{
		std::string status = " is not signed";
		out << form.getName() << status << ".Required grade to be signed" << form.getGradeToSign() << ", and required grade to be executed: " << form.getGradeToExecute();
	}
	return out;
}
