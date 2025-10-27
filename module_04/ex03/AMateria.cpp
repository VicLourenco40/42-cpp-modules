#include <iostream>
#include "AMateria.hpp"

AMateria::AMateria(void) : type("None")
{
	std::cout << "AMateria default constructor called\n";
}

AMateria::AMateria(const std::string& type) : type(type)
{
	std::cout << "AMateria constructor called\n";
}

AMateria::AMateria(const AMateria& other) : type(other.type)
{
	std::cout << "AMateria copy constructor called\n";
}

AMateria::~AMateria(void)
{
	std::cout << "AMateria destructor called\n";
}

AMateria& AMateria::operator=(const AMateria& other)
{
	std::cout << "AMateria assignment operator called\n";
	type = other.type;
	return *this;
}

const std::string& AMateria::getType(void) const
{
	return type;
}
