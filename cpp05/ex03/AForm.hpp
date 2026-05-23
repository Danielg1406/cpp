# ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include <exception>
#include <string>

class Bureaucrat;

class AForm {
    private:
        const std::string _name;
        bool _isSigned;
        const int _gradeToSign;
        const int _gradeToExecute;
    public:
        AForm(const std::string &name, int const gradeToSign, int const gradeToExecute);
        AForm(const AForm &other);
        AForm &operator=(const AForm &other);
        virtual ~AForm();

        const std::string &getName() const;
        bool getIsSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;

        void beSigned(const Bureaucrat &bureaucrat);
        void execute(Bureaucrat const & executor) const;
        virtual void action() const = 0;

        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
    
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
    
        class NotSignedException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};
std::ostream &operator<<(std::ostream &out, const AForm &form);

#endif
