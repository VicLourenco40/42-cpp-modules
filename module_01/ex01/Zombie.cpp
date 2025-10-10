#include <iostream>

#include "Zombie.hpp"

Zombie::~Zombie()
{
	std::cout << name << " destroyed\n";
}

void Zombie::announce() const
{
	std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}

void Zombie::setName(std::string newName)
{
	name = newName;
}
