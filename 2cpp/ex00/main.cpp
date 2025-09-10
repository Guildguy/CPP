#include "Fixed.hpp"

int main(void)
{
	Fixed a; //CRIAÇÃO DO OBJETO
	Fixed b(a); //CONSTRUTOR DE CÓPIA
	Fixed c; //CRIAÇÃO DE OUTRO OBJETO

	c = b; //ATRIBUIÇÃO DE CÓPIA

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	return 0;
}
