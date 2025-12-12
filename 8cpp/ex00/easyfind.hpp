#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <exception>
#include <vector>
#include <list>
#include <algorithm>

template <typename T>
typename T::iterator	easyfind(T& container, int value);

#include "easyfind.tpp"

#endif
