#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base*	generate(void)
{
	static bool	rand_exist = false;

	if (!rand_exist)
	{
		std::srand(std::time(0));
		rand_exist = true;
	}
	int random = std::rand() % 3;

	switch (random) {
		case 0:
			return (new A());
		case 1:
			return (new B());
		case 2:
			return (new C());
		default:
			return (NULL);
	}
}

void	indentify(Base* p)
{
	//std::string	ptr = 
}

void	indentify(Base& p)
{
	
}
