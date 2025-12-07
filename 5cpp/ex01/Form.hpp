#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <exception>

class	Bureaucrat;

class	Form
{
	private:
		const std::string	name;
		bool				isSigned; //false
		const int			signedRating;
		const int			signedExec;
	public:
		Form();
		~Form();

		Form(const Form &copy);
		Form& operator=(const Form& form);
		Form(const std::string name, int gradeToSign, int gradeToExec);

		class GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

		std::string	getName() const;
		bool		getIsSigned() const;
		int			getSignedRating() const;
		int			getSignedExec() const;

		void		beSigned(const Bureaucrat& person);
		void		signForm(const Form &form);
};

std::ostream&	operator<<(std::ostream& os, Form& form);

#endif