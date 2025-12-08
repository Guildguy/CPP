#ifndef INTERN_HPP
#define INTERN_HPP

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class	Intern
{
	private:
        AForm* createShrubbery(const std::string& target);
        AForm* createRobotomy(const std::string& target);
        AForm* createPardon(const std::string& target);
	public:
		// CANONICAL ORTHODOX FORM
		Intern();
		Intern(const Intern& copy);
		Intern& operator=(const Intern& intern);
		~Intern();

		//FUNCTION POINTER
		AForm*	makeForm(std::string const &form, std::string const &target);
};

#endif