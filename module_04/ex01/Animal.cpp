#include <iostream>
#include "Animal.hpp"

Animal::Animal(void) : type("Any")
{
	std::cout << "Animal default constructor called\n";
}

Animal::Animal(const Animal& other) : type(other.type)
{
	std::cout << "Animal copy constructor called\n";
}

Animal::~Animal(void)
{
	std::cout << "Animal destructor called\n";
}

Animal& Animal::operator=(const Animal& other)
{
	std::cout << "Animal assignment operator called\n";
	type = other.type;
	return *this;
}

const std::string& Animal::getType(void) const
{
	return type;
}

void Animal::makeSound(void) const
{
	std::cout << "Sound\n";
}
