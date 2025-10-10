#include "Zombie.hpp"

int	main()
{
	int n = 3;
	Zombie* zombies = zombieHorde(n, "zombie");
	for (int i = 0; i < n; i++)
		zombies[i].announce();
	delete[] zombies;
}
