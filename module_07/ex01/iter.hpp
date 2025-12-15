#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template<typename T>
void iter(T *const arr, const std::size_t len, void (*const f)(T&))
{
	if (!arr || !f)
		return;
	for (std::size_t i = 0; i < len; i++)
		f(arr[i]);
}

template<typename T>
void iter(const T *const arr, const std::size_t len, void (*const f)(const T&))
{
	if (!arr || !f)
		return;
	for (std::size_t i = 0; i < len; i++)
		f(arr[i]);
}

template<typename T>
void print(const T& e)
{
	std::cout << e << '\n';
}

template<typename T>
void increment(T& e)
{
	e++;
}

#endif
