#include <iostream>

#include "HumanB.hpp"

HumanB::HumanB(const std::string& name) : name(name) {}

void HumanB::setWeapon(Weapon& newWeapon)
{
	weapon = &newWeapon;
}

void HumanB::attack() const
{
	if (!weapon)
	{
		std::cout << name << " has no weapon to attack with\n";
		return;
	}
	std::cout << name << " attacks with their " << weapon->getType() << '\n';
}
