#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "Bureaucrat.hpp"
#include "AForm.hpp"

class	AForm;

class	ShrubberyCreationForm
{
	private:
		std::string	target;
	public:
		//CANONNICAL ORTODOXICAL FORM
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm& copy);
		ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& form);
		~ShrubberyCreationForm();
};


#endif
