#include "easyfind.hpp"

const char* NotFoundException::what(void) const throw()
{
	return "Element not found";
}
