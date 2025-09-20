#ifndef DOG_HPP
# define DOG_HPP

# include "Brain.hpp"

class Dog : public Brain
{
	private:
		Brain*	brain;

	public:
		Dog();
		~Dog();

		Dog(const Dog& copy);
		Dog	operator=(const Dog& Dog);

		void	makeSound() const;
};

#endif