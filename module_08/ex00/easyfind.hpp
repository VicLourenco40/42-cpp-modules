#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <exception>

class NotFoundException : public std::exception
{
	const char* what(void) const throw();
};

template<typename T>
typename T::iterator easyfind(T& c, int e);

template<typename T>
typename T::const_iterator easyfind(const T& c, int e);

#include "easyfind.tpp"

#endif
