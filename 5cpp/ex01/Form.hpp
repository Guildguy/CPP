#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

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

		std::string	getName() const;
		bool		getIsSigned() const;
		int			getSignedRating() const;
		int			getSignedExec() const;

		void		beSigned(const Bureaucrat& person);
};

std::ostream&	operator<<(std::ostream& os, Form& form);

#endif