#ifndef	SERIALIZER_HPP
#define	SERIALIZER_HPP

#include <iostream>
#include <cstdint>

//REITERPRET_CAST: "Take these bits and pretend they're this other type. Don't change the bits, just change the label."
typedef struct	Data
{
	int			id;
	std::string	name;
	double		value;
}				Data;

class Serializer
{
	private:
		Serializer();
		Serializer(const Serializer& copy);
		Serializer&	operator=(const Serializer& serial);
		~Serializer();
	public:
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
};

#endif