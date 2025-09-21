#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"
# include "Brain.hpp"

class WrongCat : public WrongAnimal
{
	private:
		Brain* brain;

	public:
		WrongCat();
		~WrongCat();


		WrongCat(const WrongCat& copy);
		WrongCat	operator=(const WrongCat& WrongCat);

		void	makeSound() const;
};

#endif
