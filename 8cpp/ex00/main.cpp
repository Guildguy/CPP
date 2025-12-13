#include "easyfind.hpp"

int main()
{
	std::vector<int> vec; //acts like an array
	std::list<int> lst; //acts like an double-linked list
	
	int	values[] = {1, 2, 3, 4, 5};

	for (int i = 0; i < 5; ++i)
	{
		vec.push_back(values[i]);
		lst.push_front(values[i]);
	}

	try
	{
		std::vector<int>::iterator itr = easyfind(vec, 3);
		std::list<int>::iterator itr_l = easyfind(lst, 2);
		std::cout << "Found: " << *itr << std::endl;
		std::cout << "Found: " << *itr_l << std::endl;
		itr = easyfind(vec, 10);
		std::cout << "Found: " << *itr << std::endl;

	}
	catch (const std::runtime_error &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	return (0);
}
