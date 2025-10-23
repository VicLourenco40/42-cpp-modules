#include <iostream>
#include "Cat.hpp"

Cat::Cat(void) : brain(new Brain())
{
	std::cout << "Cat default constructor called\n";
	type = "Cat";
}

Cat::Cat(const Cat& other) : brain(new Brain(*other.brain))
{
	std::cout << "Cat copy constructor called\n";
	type = other.type;
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called\n";
	delete brain;
}

Cat& Cat::operator=(const Cat& other)
{
	std::cout << "Cat assignment operator called\n";
	type = other.type;
	*brain = *other.brain;
	return *this;
}

void Cat::makeSound(void) const
{
	std::cout << "Meow!\n";
}
