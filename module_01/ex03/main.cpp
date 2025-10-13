#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	{
		Weapon club = Weapon("crude spiked club");
		Weapon knife = Weapon("knife");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
		bob.setWeapon(knife);
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		Weapon knife = Weapon("knife");
		HumanB jim("Jim");
		jim.attack();
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
		jim.setWeapon(knife);
		jim.attack();
	}
}
