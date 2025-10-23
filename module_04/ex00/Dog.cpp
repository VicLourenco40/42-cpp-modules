#include <iostream>
#include "Dog.hpp"

Dog::Dog(void)
{
	std::cout << "Dog default constructor called\n";
	type = "Dog";
}

Dog::Dog(const Dog& other)
{
	std::cout << "Dog copy constructor called\n";
	type = other.type;
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor called\n";
}

Dog& Dog::operator=(const Dog& other)
{
	std::cout << "Dog assignment operator called\n";
	type = other.type;
	return *this;
}

void Dog::makeSound(void) const
{
	std::cout << "Bark!\n";
}
