#include <iostream>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap() :
	name("Robot"), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "Default constructor called\n";
}

ClapTrap::ClapTrap(const std::string& name) :
	name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "Constructor called\n";
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called\n";
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	std::cout << "Copy constructor called\n";
	*this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << "Assignment operator called\n";
	name = other.name;
	hitPoints = other.hitPoints;
	energyPoints = other.energyPoints;
	attackDamage = other.attackDamage;
	return *this;
}

bool ClapTrap::isAlive() const
{
	if (!hitPoints)
		std::cout << "ClapTrap " << name << " is out of order.\n";
	return hitPoints;
}

bool ClapTrap::hasEnergy() const
{
	if (!energyPoints)
		std::cout << "ClapTrap " << name << " has no energy points.\n";
	return energyPoints;
}

void ClapTrap::attack(const std::string& target)
{
	if (!isAlive() || !hasEnergy())
		return;
	std::cout << "ClapTrap " << name << " attacks " << target <<
		", causing " << attackDamage << " points of damage!\n";
	energyPoints--;
}

void ClapTrap::takeDamage(unsigned int damage)
{
	std::cout << "ClapTrap " << name << " receives " << damage <<
		" points of damage!\n";
	if (damage >= hitPoints)
	{
		hitPoints = 0;
		isAlive();
	}
	else
	{
		hitPoints -= damage;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (!isAlive() || !hasEnergy())
		return;
	std::cout << "ClapTrap " << name << " repairs himself, regaining " <<
		amount << " hit points.\n";
	hitPoints += amount;
	energyPoints--;
}
