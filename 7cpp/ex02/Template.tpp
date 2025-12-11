#include <iostream>
#include <Array.hpp>

template <typename T>
Array<T>::Array() {}

template <typename T>
Array<T>::Array(unsigned int n) {}

template <typename T>
Array<T>::Array(const Array& copy) {}

template <typename T>
Array<T>&	Array<T>::operator=(const Array& arr) {}

template <typename T>
Array<T>::~Array() {}

template <typename T>
T&	Array<T>::operator[](unsigned int i) {}

template <typename T>
const T&	Array<T>::operator[](unsigned int i) const {}

template <typename T>
unsigned int	Array<T>::size(void) const {}
