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
AForm* makeShrubbery(const std::string& target)
{
	return new ShrubberyCreationForm(target);
}

AForm* makeRobotomy(const std::string& target)
{
	return new RobotomyRequestForm(target);
}

AForm* makePardon(const std::string& target)
{
	return new PresidentialPardonForm(target);
}

//FUNCTION POINTER
typedef AForm* (*FormCreator)(const std::string &);

AForm*	makeForm(std::string const &form, std::string const &target)
{
    std::string names[3] =
	{
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    FormCreator creators[3] =
	{
        &makeShrubbery,
        &makeRobotomy,
        &makePardon
    };

    for (int i = 0; i < 3; i++)
    {
        if (form == names[i])
        {
            std::cout << "Intern creates " << form << std::endl;
            return (creators[i](target));
        }
    }
    std::cout << "Error: form not found!" << std::endl;
    return (NULL);
}
