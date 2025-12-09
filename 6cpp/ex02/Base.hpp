#ifndef	BASE_HPP
#define BASE_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <exception>

//Dynamic cast
class	Base
{
	public:
		Base(void) {};
		virtual ~Base(void) {};
};

Base*	generate(void);
void	indentify(Base* p);
void	indentify(Base& p);

#endif
