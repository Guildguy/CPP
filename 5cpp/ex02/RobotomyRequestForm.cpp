#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"

//CANONNICAL ORTODOXICAL FORM
RobotomyRequestForm::RobotomyRequestForm() : 
AForm("RobotomyRequestForm", 72, 45),
target("default") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : 
AForm("RobotomyRequestForm", 72, 45), 
target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy) :
AForm(copy), 
target(copy.target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& form)
{
    if (this != &form)
	{
		AForm::operator=(form);
        this->target = form.target;
	}
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::exec() const {
    
    static bool rand_exist = false;

    // seed the random generator
    if (!rand_exist) {
        std::srand(std::time(0));
        rand_exist = true;
    }

    // get 50% chance
    if (std::rand() % 2 == 0) {
        std::cout << "SKREEEEEEEEE!\n"
                  << target << " has been robotomized successfully."
                  << std::endl;
    }
    else {
        std::cout << "VRRRRR-ZZZZT-POP...\n"
                  << target << "'s robotomy has failed!"
                  << std::endl;
    }
}
