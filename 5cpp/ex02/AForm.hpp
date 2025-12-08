#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>

class	Bureaucrat;

class	AForm
{
	private:
		const std::string	name;
		bool				isSigned; //false
		const int			signedRating;
		const int			signedExec;
	protected:
        virtual void exec() const = 0;
	public:
		//CANONNICAL ORTODOXICAL FORM
		AForm();
		AForm(const std::string name, int gradeToSign, int gradeToExec);
		AForm(const AForm &copy);
		AForm& operator=(const AForm& form);
		virtual ~AForm();

		//GETTERS
		std::string	getName() const;
		bool		getIsSigned() const;
		int			getSignedRating() const;
		int			getSignedExec() const;

		//AUX
		void		beSigned(const Bureaucrat& person);

		//EXCEPTION HANDLER
		class	GradeTooLowException : public std::exception //exceptions
		{
			public:
				virtual const char* what() const throw();
		};

		class	GradeTooHighException : public std::exception //exceptions
		{
			public:
				virtual const char* what() const throw();
		};

		class	FormNotSignedException : public std::exception //exceptions
		{
			public:
				virtual const char* what() const throw();
		};

		//PURE VIRTUAL METHOD
		virtual void execute(Bureaucrat const & executor) const;
};

std::ostream&	operator<<(std::ostream& os, const AForm& form);

#endif
