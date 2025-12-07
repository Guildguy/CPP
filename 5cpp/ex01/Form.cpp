#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : 
name(NULL), 
isSigned(false), 
signedRating(0), 
signedExec(0)
{
	if (gradeToSign < 1 || gradeToExec < 1)
		throw Form::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExec > 150)
		throw Form::GradeTooLowException();
}

Form::~Form() {}

Form::Form(const Form &copy) : 
name(copy.name), 
isSigned(copy.isSigned), 
signedRating(copy.signedRating), 
signedExec(copy.signedExec) {}

Form&	Form::operator=(const Form& form)
{
	(void)form;
	return (*this);
}

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

void	Form::beSigned(const Bureaucrat& person)
{
	if (person.getGrade() > this.signedRating)
		throw	Form::GradeTooLowExeption();
	this->isSigned = true;
}

std::ostream&	operator<<(std::ostream& os, Form& form)
{
	return (os << form.getName() << ", bureaucrat w/ grade " << form.getGrade());
}
