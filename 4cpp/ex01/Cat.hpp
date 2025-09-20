#ifndef CAT_HPP
# define CAT_HPP

# include "Brain.hpp"

class Cat : public Brain
{
	private:
		Brain*	brain;

	public:
		Cat();
		~Cat();

		Cat(const Cat& copy);
		Cat	operator=(const Cat& Cat);

		void	makeSound() const;
};

#endif