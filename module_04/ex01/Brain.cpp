#include <iostream>
#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor called\n";
}

Brain::Brain(const Brain& other)
{
	std::cout << "Brain copy constructor called\n";
	for (unsigned int i = 0; i < num_ideas; ++i)
		ideas[i] = other.ideas[i];
}

Brain::~Brain(void)
{
	std::cout << "Brain destructor called\n";
}

Brain& Brain::operator=(const Brain& other)
{
	std::cout << "Brain assignment operator called\n";
	for (unsigned int i = 0; i < num_ideas; ++i)
		ideas[i] = other.ideas[i];
	return *this;
}
