#include <iostream>
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : type("Any")
{
	std::cout << "WrongAnimal default constructor called\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : type(other.type)
{
	std::cout << "WrongAnimal copy constructor called\n";
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal destructor called\n";
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
	std::cout << "WrongAnimal assignment operator called\n";
	type = other.type;
	return *this;
}

const std::string& WrongAnimal::getType(void) const
{
	return type;
}

void WrongAnimal::makeSound(void) const
{
	std::cout << "Sound\n";
}
