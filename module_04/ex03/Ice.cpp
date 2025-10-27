#include <iostream>
#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice(void) : AMateria("ice")
{
	std::cout << "Ice default constructor called\n";
}

Ice::Ice(const Ice& other) : AMateria(other)
{
	std::cout << "Ice copy constructor called\n";
}

Ice::~Ice(void)
{
	std::cout << "Ice destructor called\n";
}

Ice& Ice::operator=(const Ice& other)
{
	std::cout << "Ice assignment operator called\n";
	AMateria::operator=(other);
	return *this;
}

Ice* Ice::clone(void) const
{
	return new Ice(*this);
}

void Ice::use(const ICharacter& target) const
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}
