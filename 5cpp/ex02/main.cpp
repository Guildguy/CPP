#include    "Bureaucrat.hpp"
#include    "AForm.hpp"
#include    "ShrubberyCreationForm.hpp"
#include    "RobotomyRequestForm.hpp"
#include    "PresidentialPardonForm.hpp"

#define     RESET "\033[0m"
#define     RED "\033[31m"
#define     GREEN "\033[32m"
#define     YELLOW "\033[33m"

int main()
{
	Bureaucrat boss("The Boss", 1);
	Bureaucrat manager("Michael Scott", 40);
	Bureaucrat intern("Stag", 149);
    ShrubberyCreationForm shrub("home");

	std::cout << "\n" << boss << std::endl;
	std::cout << manager << std::endl;
	std::cout << intern << std::endl;
	std::cout << YELLOW << "\n----------------------------------------" << std::endl;
	std::cout << "TEST 1: SHRUBBERY CREATION FORM (Sign: 145, Exec: 137)" << std::endl;
	std::cout << "----------------------------------------" << RESET << std::endl;

	intern.executeForm(shrub);
	intern.signForm(shrub);
	boss.signForm(shrub);
	intern.executeForm(shrub);
	manager.executeForm(shrub);

	std::cout << GREEN << "[!] Check if 'home_shrubbery' file was created." << RESET << std::endl;

    /* *************************************************************************** */

	RobotomyRequestForm robot("Zepellin");

	std::cout << YELLOW << "\n----------------------------------------" << std::endl;
	std::cout << "TEST 2: ROBOTOMY REQUEST FORM (Sign: 72, Exec: 45)" << std::endl;
	std::cout << "----------------------------------------" << RESET << std::endl;

	manager.signForm(robot);
	std::cout << "Attempt 1:" << std::endl;
	manager.executeForm(robot);
	std::cout << "Attempt 2:" << std::endl;
	manager.executeForm(robot);
	std::cout << "Attempt 3:" << std::endl;
	manager.executeForm(robot);
	std::cout << "Attempt 4:" << std::endl;
	manager.executeForm(robot);

    /* *************************************************************************** */
    
	PresidentialPardonForm pardon("Arthur Dent");

	std::cout << YELLOW << "\n----------------------------------------" << std::endl;
	std::cout << "TEST 3: PRESIDENTIAL PARDON FORM (Sign: 25, Exec: 5)" << std::endl;
	std::cout << "----------------------------------------" << RESET << std::endl;

	manager.signForm(pardon);
	boss.signForm(pardon);
	manager.executeForm(pardon);
	boss.executeForm(pardon);

	return (0);
}