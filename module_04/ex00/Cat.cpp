#include <iostream>
#include "Cat.hpp"

Cat::Cat(void)
{
	std::cout << "Cat default constructor called\n";
	type = "Cat";
}

Cat::Cat(const Cat& other)
{
	std::cout << "Cat copy constructor called\n";
	type = other.type;
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called\n";
}

Cat& Cat::operator=(const Cat& other)
{
	std::cout << "Cat assignment operator called\n";
	type = other.type;
	return *this;
}

void Cat::makeSound(void) const
{
	std::cout << "Meow!\n";
}
