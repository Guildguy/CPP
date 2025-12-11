#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template	<typename T>
void	iter(T* arr, size_t lenght, void (*func)(T&)) 
{
	if (!arr || !func)
		return ;
	for (size_t i = 0; i < lenght; i++)
		func(arr[i]);
}

template	<typename T>
void	iter(const T* arr, size_t lenght, void (*func)(const T&)) 
{
	if (!arr || !func)
		return ;
	for (size_t i = 0; i < lenght; i++)
		func(arr[i]);
}

template <typename T>
void printOnCPP(T &i) 
{
	std::cout << i << std::endl;
}

void addOne(int &i)
{
	i++;
}

#endif