#include "Bureaucrat.hpp"

//CANONNICAL ORTODOXICAL FORM
Bureaucrat::Bureaucrat(void) : 
name("Marquinhos"), 
grade(1) {}

Bureaucrat::Bureaucrat(const std::string name, int grade) : 
name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : 
name(copy.name), 
grade(copy.grade) {}

Bureaucrat&	Bureaucrat::operator=(const	Bureaucrat &bureaucrat)
{
	if (this != &bureaucrat)
		this->grade = bureaucrat.grade;
	return (*this);
}

Bureaucrat::~Bureaucrat(void) {}

//GETTERS
int	Bureaucrat::getGrade() const
{
	return (this->grade);
}

const std::string	Bureaucrat::getName() const
{
	return (this->name);
}

//AUX
void	Bureaucrat::increment()
{
	if (grade > 1)
		this->grade--;
	else
		throw GradeTooHighException();
}

void	Bureaucrat::decrement()
{
	if (grade < 150)
		this->grade++;
	else
		throw GradeTooLowException();
}

void	Bureaucrat::signForm(Form& form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->name << " signed " << form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << this->name << " couldn't sign "
		<< form.getName() << " because " << e.what() << std::endl; 
	}
}

//EXCEPTION HANDLER
const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
	return (os << bureaucrat.getName() << ", bureaucrat w/ grade " << bureaucrat.getGrade());
}
