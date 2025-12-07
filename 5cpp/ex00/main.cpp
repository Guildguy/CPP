#include "Bureaucrat.hpp"

int	main()
{
	
	try
	{
		Bureaucrat	person("Jonas", 150);
		std::cout << person << " was successfully created" << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout
		<< "Bureaucrat was not created due to exception: "
		<< e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout
		<< "Bureaucrat was not created due to exception: "
		<< e.what() << std::endl;
	}

/***************************************************/
	try
	{
		Bureaucrat	person("João", -42);
		std::cout << person << " was successfully created" << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout
		<< "Bureaucrat was not created due to exception: "
		<< e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout
		<< "Bureaucrat was not created due to exception: "
		<< e.what() << std::endl;
	}
	
/***************************************************/
	try
	{
		Bureaucrat	person("Jaqueline", 151);
		std::cout << std::endl << person << " was successfully created" << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout
		<< "Bureaucrat was not created due to exception: "
		<< e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout
		<< "Bureaucrat was not created due to exception: "
		<< e.what() << std::endl;
	}
	
/***************************************************/
	try
	{
		Bureaucrat	person("Jeremias", 3);
		std::cout << std::endl << person << " was successfully created" << std::endl;
		person.increment();
		std::cout << person << " was incremented" << std::endl;
		person.increment();
		std::cout << person << " was incremented" << std::endl;

		Bureaucrat	newPerson("Jaime", 149);
		std::cout << std::endl << newPerson << " was successfully created" << std::endl;
		newPerson.decrement();
		std::cout << newPerson << " was decremented" << std::endl;
		newPerson.decrement();
		std::cout << newPerson << " was decremented" << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout
		<< "Bureaucrat was not incremented due to exception: "
		<< e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout
		<< "Bureaucrat was not decremented due to exception: "
		<< e.what() << std::endl;
	}
	return (0);
}
