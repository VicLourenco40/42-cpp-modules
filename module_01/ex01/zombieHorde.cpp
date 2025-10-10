#include "Zombie.hpp"
#include <cstdlib>

Zombie* zombieHorde(int n, std::string name)
{
	if (n < 0)
		return (NULL);
	Zombie* zombies = new Zombie[n];
	for (int i = 0; i < n; i++)
		zombies[i].setName(name);
	return zombies;
}
