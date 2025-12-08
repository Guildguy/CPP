#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"

int main()
{
    Intern		intern;
    Bureaucrat	boss("Big Boss", 1);
    AForm*		form;

    std::cout << YELLOW << "\n[TEST 1] Creating 'robotomy request'" << RESET << std::endl;
    form = intern.makeForm("robotomy request", "Bender");
    if (form)
    {
        boss.signForm(*form);
        boss.executeForm(*form);
        delete form;
    }

    /* *************************************************************************** */

    std::cout << YELLOW << "\n[TEST 2] Creating 'shrubbery creation'" << RESET << std::endl;
    form = intern.makeForm("shrubbery creation", "Garden");
    if (form)
    {
        boss.signForm(*form);
        boss.executeForm(*form);
        delete form;
    }

    /* *************************************************************************** */

    std::cout << YELLOW << "\n[TEST 3] Creating 'presidential pardon'" << RESET << std::endl;
    form = intern.makeForm("presidential pardon", "Ford Prefect");
    if (form)
    {
        boss.signForm(*form);
        boss.executeForm(*form);
        delete form;
    }

	/* *************************************************************************** */
	
    std::cout << YELLOW << "\n[TEST 4] Trying to create a non-existent form" << RESET << std::endl;
    form = intern.makeForm("salary increase", "Myself");
    if (form)
    {
        std::cout << "This should not appear." << std::endl;
        delete form;
    }
    else
        std::cout << RED << "Success: Invalid form correctly returned NULL." << RESET << std::endl;

    return (0);
}
