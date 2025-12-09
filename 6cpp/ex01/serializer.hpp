#ifndef	SERIALIZER_HPP
#define	SERIALIZER_HPP

#include <cstdint>

typedef struct	Data
{
	uintptr_t	*n;
}				Data;


class Serializer
{
	private:
		Serializer();
		Serializer(const Serializer& copy);
		Serializer&	operator=(const Serializer& serial);
		~Serializer();
	public:
		uintptr_t	serialize(Data* ptr);
		Data*		deserialize(uintptr_t raw);
};

#endif