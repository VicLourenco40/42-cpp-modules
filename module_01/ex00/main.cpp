#include "Zombie.hpp"

int	main()
{
	Zombie* heapZombie = newZombie("heap");
	randomChump("stack");
	heapZombie->announce();
	delete heapZombie;
}
