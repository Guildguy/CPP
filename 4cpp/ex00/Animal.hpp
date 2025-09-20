#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
	protected:
		std::string	type;

	public:
		Animal();
		~Animal();

		Animal(const Animal& copy);
		Animal&	operator=(const Animal& Animal);

		std::string	getType() const;
		virtual void	makeSound() const;
};

std::ostream&	operator<<(std::ostream& os, const Animal& Animal);

#endif
