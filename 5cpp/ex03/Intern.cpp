#include "AForm.hpp"
#include "Intern.hpp"

// CANONICAL ORTHODOX FORM
Intern::Intern() {}

Intern::Intern(const Intern& copy)
{
    (void)copy;
}

Intern& Intern::operator=(const Intern& intern)
{
	(void)intern;
	return (*this);
}

Intern::~Intern() {}

//FORM FUNCTIONS
AForm*  Intern::createShrubbery(const std::string& target)
{
	return new ShrubberyCreationForm(target);
}

AForm*  Intern::createRobotomy(const std::string& target)
{
	return new RobotomyRequestForm(target);
}

AForm*  Intern::createPardon(const std::string& target)
{
	return new PresidentialPardonForm(target);
}

//FUNCTION POINTER
AForm*	Intern::makeForm(std::string const &form, std::string const &target)
{
    std::string names[] =
	{
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    typedef AForm* (Intern::*FPointer)(const std::string&);
    FPointer creators[] =
	{
        &Intern::createShrubbery,
        &Intern::createRobotomy,
        &Intern::createPardon
    };

    for (int i = 0; i < 3; i++)
    {
        if (form == names[i])
        {
            std::cout << "Intern creates " << form << std::endl;
            return ((this->*creators[i])(target));
        }
    }
    std::cout << "Error: form not found!" << std::endl;
    return (NULL);
}
