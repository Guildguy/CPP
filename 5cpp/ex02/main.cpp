#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() 
{
    std::cout << "\n--- 1. INVALID FORM CREATION TEST ---" << std::endl;
    try 
    {
        Form wrong("WrongForm", 0, 50);
    } 
    catch (std::exception &e) 
    {
        std::cout << "Successfully caught error: " << e.what() << std::endl;
    }

    std::cout << "\n--- 2. SUCCESSFUL SIGNATURE TEST ---" << std::endl;
    try 
    {
        Bureaucrat  boss("Boss", 1);
        Form        contract("Contract A", 50, 50);

        std::cout << boss << std::endl;
        std::cout << contract << std::endl;

        boss.signForm(contract);
        
        std::cout << contract << std::endl;
    } 
    catch (std::exception &e) 
    {
        std::cout << "Unexpected error: " << e.what() << std::endl;
    }

    std::cout << "\n--- 3. SIGNATURE WITHOUT SUFFICIENT GRADE TEST ---" << std::endl;
    try 
    {
        Bureaucrat  peasant("Peasant", 150);
        Form        topSecret("Top Secret Docs", 10, 10);

        std::cout << peasant << std::endl;
        std::cout << topSecret << std::endl;

        peasant.signForm(topSecret);

        std::cout << topSecret << std::endl;
    } 
    catch (std::exception &e) 
    {
        std::cout << "Critical error: " << e.what() << std::endl;
    }

    return (0);
}
