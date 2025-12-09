#include "serializer.hpp"

//CANONNICAL ORTODOXICAL FORM
Serializer::Serializer() {}

Serializer::Serializer(const Serializer& copy)
{
	(void)copy;
}

Serializer&	Serializer::operator=(const Serializer& serial)
{
	(void)serial; return *this;
}

Serializer::~Serializer() {}

//Reinterpret the bits of the memory address as an integer.
uintptr_t	Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

// Take the integer and say "this here is a memory address of Data"
Data*	Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}
