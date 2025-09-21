#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
	protected:
		std::string	type;

	public:
		Animal();
		virtual ~Animal();

		Animal(const Animal& copy);
		Animal&	operator=(const Animal& Animal);

		std::string	getType() const;
		virtual void	makeSound() const = 0;
};

std::ostream&	operator<<(std::ostream& os, const Animal& Animal);

#endif
