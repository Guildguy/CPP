#include <iostream>

//CANONNICAL ORTODOXICAL FORM
template <typename T>
Array<T>::Array() :
_data (NULL),
_size(0)
{}

template <typename T>
Array<T>::Array(unsigned int n) :
_data(NULL),
_size(n)
{
	if (n > 0)
		this->_data = new T[n]();
	else
		this->_data = NULL;
}

template <typename T>
Array<T>::Array(const Array& copy) :
_data(NULL),
_size(0)
{
	*this = copy;
}

template <typename T>
Array<T>&	Array<T>::operator=(const Array& arr)
{
	if (this != &arr)
	{
		if (this->_data)
			delete[] this->_data;
		this->_size = arr._size;
		if (arr._size > 0)
		{
			this->_data = new T[arr._size];
			for (unsigned int i = 0; i < arr._size; i++)
				this->_data[i] = arr._data[i];
		}
		else
			this->_data = NULL;
	}
	return (*this);
}

template <typename T>
Array<T>::~Array()
{
	if (this->_data)
		delete[] this->_data;
}

//OVERLOAD
template <typename T>
T&	Array<T>::operator[](unsigned int i)
{
	if (i >= this->_size)
		throw OutOfBoundsException();
	return (this->_data[i]);
}

template <typename T>
const T&	Array<T>::operator[](unsigned int i) const
{
	if (i >= this->_size)
		throw OutOfBoundsException();
	return (this->_data[i]);
}

//AUX
template <typename T>
unsigned int	Array<T>::size(void) const
{
	return (this->_size);
}
