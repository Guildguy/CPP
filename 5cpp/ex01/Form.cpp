#include "Form.hpp"
#include "Bureaucrat.hpp"

//CANONNICAL ORTODOXICAL FORM
Form::Form() : 
name("Wrong form"), 
isSigned(false), 
signedRating(0), 
signedExec(0)
{
	if (signedRating < 1 || signedExec < 1)
        throw GradeTooHighException();
    if (signedRating > 150 || signedExec > 150)
        throw GradeTooLowException();
}

Form::Form(const std::string name, int gradeToSign, int gradeToExec) :
name(name),
isSigned(false),
signedRating(gradeToSign),
signedExec(gradeToExec)
{
	if (gradeToSign < 1 || gradeToExec < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExec > 150)
		throw GradeTooLowException();
}

Form::Form(const Form &copy) : 
name(copy.name), 
isSigned(copy.isSigned), 
signedRating(copy.signedRating), 
signedExec(copy.signedExec) {}

Form&	Form::operator=(const Form& form)
{
	if (this != &form)
		this->isSigned = form.getIsSigned();
	return (*this);
}

Form::~Form() {}

//GETTERS
std::string	Form::getName() const
{
    return (this->name);
}

bool	Form::getIsSigned() const
{
    return (this->isSigned);
}

int		Form::getSignedRating() const
{
    return (this->signedRating);
}

int		Form::getSignedExec() const
{
    return (this->signedExec);
}

//AUX
void	Form::beSigned(const Bureaucrat& person)
{
	if (person.getGrade() > this->signedRating)
		throw	Form::GradeTooLowException();
	this->isSigned = true;
}

//EXCEPTION HANDLER
const char* Form::GradeTooHighException::what() const throw()
{
	return ("Form grade is too high!");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Form grade is too low!");
}

std::ostream&	operator<<(std::ostream& os, const Form& form)
{
	return (os << "Form " << form.getName() 
       << ", status: " << (form.getIsSigned() ? "signed" : "not signed")
       << ", sign grade: " << form.getSignedRating()
       << ", exec grade: " << form.getSignedExec());
}
