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
