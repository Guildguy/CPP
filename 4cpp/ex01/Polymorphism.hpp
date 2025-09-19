#ifndef POLYMORPHISM_HPP
# define POLYMORPHISM_HPP

# include <iostream>

class Animal
{
	private:
		std::string	type;

	public:
		Animal();
		~Animal();

		Animal(const Animal& copy);
		Animal&	operator=(const Animal& Animal);
};

//std::ostream&	operator<<();

#endif