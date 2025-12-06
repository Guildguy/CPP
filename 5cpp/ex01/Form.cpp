#include "Form.hpp"

Form::Form() : 
name(NULL), 
isSigned(false), 
signedRating(0), 
signedExec(0)
{
	//try catch
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

int	Form::getSignedRating() const
{
    return (this->signedRating);
}

int	Form::getSignedExec() const
{
    return (this->signedExec);
}