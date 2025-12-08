#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

//CANONNICAL ORTODOXICAL FORM
ShrubberyCreationForm::ShrubberyCreationForm() : 
AForm("ShrubberyCreationForm", 145, 137),
target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : 
AForm("ShrubberyCreationForm", 145, 137), 
target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy) :
AForm(copy), 
target(copy.target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& form)
{
    if (this != &form)
	{
		AForm::operator=(form);
        this->target = form.target;
	}
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::exec() const
{
    std::string fileName = this->target + "_shrubbery";
    
    std::ofstream outfile(fileName.c_str());
    
    if (!outfile.is_open())
    {
        std::cerr << "Erro ao criar o arquivo de shrubbery." << std::endl;
        return ;
    }

    outfile << "       _-_" << std::endl;
    outfile << "    /~~   ~~\\" << std::endl;
    outfile << " /~~         ~~\\" << std::endl;
    outfile << "{               }" << std::endl;
    outfile << " \\  _-     -_  /" << std::endl;
    outfile << "   ~  \\\\ //  ~" << std::endl;
    outfile << "_- -   | | _- _" << std::endl;
    outfile << "  _ -  | |   -_" << std::endl;
    outfile << "      // \\\\" << std::endl;

    outfile.close();
}
