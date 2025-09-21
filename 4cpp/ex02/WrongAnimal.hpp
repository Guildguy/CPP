#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal
{
	protected:
		std::string	type;

	public:
		WrongAnimal();
		~WrongAnimal();

		WrongAnimal(const WrongAnimal& copy);
		WrongAnimal&	operator=(const WrongAnimal& WrongAnimal);

		std::string	getType() const;
		void	makeSound() const;
};

std::ostream&	operator<<(std::ostream& os, const WrongAnimal& WrongAnimal);

#endif
