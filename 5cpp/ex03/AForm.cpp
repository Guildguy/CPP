#include "AForm.hpp"
#include "Bureaucrat.hpp"

//CANONNICAL ORTODOXICAL FORM
AForm::AForm() : 
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

AForm::AForm(const std::string name, int gradeToSign, int gradeToExec) :
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

AForm::AForm(const AForm &copy) : 
name(copy.name), 
isSigned(copy.isSigned), 
signedRating(copy.signedRating), 
signedExec(copy.signedExec) {}

AForm&	AForm::operator=(const AForm& form)
{
	if (this != &form)
		this->isSigned = form.getIsSigned();
	return (*this);
}

AForm::~AForm() {}

//GETTERS
std::string	AForm::getName() const
{
    return (this->name);
}

bool	AForm::getIsSigned() const
{
    return (this->isSigned);
}

int		AForm::getSignedRating() const
{
    return (this->signedRating);
}

int		AForm::getSignedExec() const
{
    return (this->signedExec);
}

//AUX
void	AForm::beSigned(const Bureaucrat& person)
{
	if (person.getGrade() > this->signedRating)
		throw	AForm::GradeTooLowException();
	this->isSigned = true;
}

//EXCEPTION HANDLER
const char* AForm::GradeTooHighException::what() const throw()
{
	return ("AForm grade is too high!");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("AForm grade is too low!");
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return ("AForm cannot be executed because it is not signed");
}

//VIRTUAL PURE METHOD
void AForm::execute(Bureaucrat const & executor) const
{
    if (this->getIsSigned() == false)
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > this->getSignedExec())
        throw AForm::GradeTooLowException();
    this->exec();
}

std::ostream&	operator<<(std::ostream& os, const AForm& form)
{
	return (os << "AForm " << form.getName() 
       << ", status: " << (form.getIsSigned() ? "signed" : "not signed")
       << ", sign grade: " << form.getSignedRating()
       << ", exec grade: " << form.getSignedExec());
}
