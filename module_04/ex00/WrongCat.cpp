#include <iostream>
#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
	std::cout << "WrongCat default constructor called\n";
	type = "Cat";
}

WrongCat::WrongCat(const WrongCat& other)
{
	std::cout << "WrongCat copy constructor called\n";
	type = other.type;
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat destructor called\n";
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
	std::cout << "WrongCat assignment operator called\n";
	type = other.type;
	return *this;
}

void WrongCat::makeSound(void) const
{
	std::cout << "Meow!\n";
}
