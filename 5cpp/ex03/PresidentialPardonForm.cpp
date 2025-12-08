#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"

//CANONNICAL ORTODOXICAL FORM
PresidentialPardonForm::PresidentialPardonForm() : 
AForm("PresidentialPardonForm", 25, 5),
target("default") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : 
AForm("PresidentialPardonForm", 25, 5), 
target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy) :
AForm(copy), 
target(copy.target) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& form)
{
    if (this != &form)
	{
		AForm::operator=(form);
        this->target = form.target;
	}
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::exec() const
{
    std::cout << "PresidentialPardonForm: Informs that " << target
              << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
