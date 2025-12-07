#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : 
name(NULL), 
isSigned(false), 
signedRating(0), 
signedExec(0)
{
	if (signedRating < 1 || signedExec < 1)
        throw GradeTooHighException();
    if (signedRating > 150 || signedExec > 150)
        throw GradeTooLowException();
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
	if (person.getGrade() > this->signedRating)
		throw	Form::GradeTooLowException();
	this->isSigned = true;
}

std::ostream&	operator<<(std::ostream& os, Form& form)
{
	return (os << "Form " << form.getName() 
       << ", status: " << (form.getIsSigned() ? "signed" : "not signed")
       << ", sign grade: " << form.getSignedRating()
       << ", exec grade: " << form.getSignedExec());
}
