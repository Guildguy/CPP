#include <iostream>
#include <string>

int	main(void)
{
	std::string 	Brain = "HI THIS IS BRAIN";
	std::string& 	RefBrain = Brain;
	std::string*	PtrBrain = &Brain;

	std::cout << "--------------------mem. address--------------------" << std::endl;
	std::cout << "Str. address: " << &Brain << std::endl;
	std::cout << "Ref. address: " <<  &RefBrain << std::endl;
	std::cout << "Ptr. address: " <<  PtrBrain << std::endl;
	std::cout << std::endl;
	
	std::cout << "--------------------str. values--------------------" << std::endl;
	std::cout << "Str. value: " << Brain << std::endl;
	std::cout << "Ref. value: " << RefBrain << std::endl;
	std::cout << "Ptr. value: " << *PtrBrain << std::endl;
	std::cout << std::endl;

	return (0);
}
