#include "MutantStack.hpp"

int main()
{
	MutantStack<int>	mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "val from top: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "stack size: " << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it; //advances (3)
	--it; //test to see if we can go back from the fist val (5)
	std::cout << "printing from bottom to top: " << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::stack<int>	s(mstack); //copy constructor
	std::cout << "\n=== Aditional tests ===\n";

	std::cout << "Top: " << mstack.top() << std::endl;

	mstack.pop();
	std::cout << "New top: " << mstack.top() << std::endl;

	std::cout << "Size: " << mstack.size() << std::endl;

	std::cout << std::endl << "Reverse it:\n";
	MutantStack<int>::reverse_iterator rIt = mstack.rbegin();
	MutantStack<int>::reverse_iterator rIte = mstack.rend();
	std::cout << "printing from top to bottom: " << std::endl;
	while (rIt != rIte)
	{
		std::cout << *rIt << std::endl;
		++rIt;
	}

	return(0);
}
