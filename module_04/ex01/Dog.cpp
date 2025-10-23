#include <iostream>
#include "Dog.hpp"

Dog::Dog(void) : brain(new Brain())
{
	std::cout << "Dog default constructor called\n";
	type = "Dog";
}

Dog::Dog(const Dog& other) : brain(new Brain(*other.brain))
{
	std::cout << "Dog copy constructor called\n";
	type = other.type;
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor called\n";
	delete brain;
}

Dog& Dog::operator=(const Dog& other)
{
	std::cout << "Dog assignment operator called\n";
	type = other.type;
	*brain = *other.brain;
	return *this;
}

void Dog::makeSound(void) const
{
	std::cout << "Bark!\n";
}
