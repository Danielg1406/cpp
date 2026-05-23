#include "AForm.hpp"
#include "Bureaucrat.hpp"

// Exceptions Message
const char* AForm::GradeTooHighException::what() const throw() {
    return "Grade too high!";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Grade too low!";
}

const char* AForm::NotSignedException::what() const throw() {
    return "Form is not signed!";
}

// Canonical Form
AForm::AForm(const std::string &name, const int gradeToSign, const int gradeToExecute): _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
}

AForm::AForm(const AForm &other)
    : _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {}

AForm &AForm::operator=(const AForm &other) {
    if (this != &other) _isSigned = other._isSigned;
    return *this;
}

AForm::~AForm() {}

// Getters
const std::string &AForm::getName() const {
    return _name;
}

bool AForm::getIsSigned() const {
    return _isSigned;
}

int AForm::getGradeToSign() const {
    return _gradeToSign;
}

int AForm::getGradeToExecute() const {
    return _gradeToExecute;
}

// Actions
void AForm::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > _gradeToSign) throw GradeTooLowException();
    _isSigned = true;
}

void AForm::execute(Bureaucrat const & executor) const {
    if (!_isSigned) throw NotSignedException();
    if (executor.getGrade() > _gradeToExecute) throw GradeTooLowException();
    action();
}

// Operator Overload
std::ostream &operator<<(std::ostream &out, const AForm &form) {
    out << "Form \"" << form.getName() << "\" (signed: " << (form.getIsSigned() ? "yes" : "no") << ") -- grade to sign: "
        << form.getGradeToSign() << ", grade to execute: " << form.getGradeToExecute();
    return out;
}
