#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template	<typename T, typename F>
void	iter(T* arr, size_t const lenght, F func) 
{
	if (!arr || !func)
		return ;
	for (size_t i = 0; i < lenght; i++)
		func(arr[i]);
}

#endif