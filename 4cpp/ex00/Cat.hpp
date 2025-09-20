#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal
{
	private:
		
	public:
		Cat();
		~Cat();


		Cat(const Cat& copy);
		Cat	operator=(const Cat& Cat);

		void	makeSound() const;
};

#endif