# ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class Form {
	private:
		const std::string	_name;
		bool			_isSigned;
		const int		_gradeToSign;
		const int		_gradeToExecute;
	public:
		Form(const std::string &name, int const gradeToSign, int const gradeToExecute);
		Form(const Form &other);
		Form& operator=(const Form &other);
		~Form();

		bool			beSigned(const Bureaucrat &bureaucrat) const;
		void			signForm();

		const std::string	&getName() const;
		bool			getStatus() const;
		int			getGradeToSign() const;
		int			getGradeToExecute() const;

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream &out,const Form &form);

#endif
