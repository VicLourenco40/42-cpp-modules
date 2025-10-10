#include <iostream>

#include "Zombie.hpp"

Zombie::Zombie(std::string name) : name(name)
{
	std::cout << name << " created\n";
}

Zombie::~Zombie()
{
	std::cout << name << " destroyed\n";
}

void Zombie::announce() const
{
	std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}
