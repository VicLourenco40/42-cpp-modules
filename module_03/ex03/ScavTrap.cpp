#include <iostream>
#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : gatekeeperMode(false)
{
	std::cout << "ScavTrap default constructor called\n";
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
}

ScavTrap::ScavTrap(const std::string& name) :
	ClapTrap(name), gatekeeperMode(false)
{
	std::cout << "ScavTrap constructor called\n";
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called\n";
}

ScavTrap::ScavTrap(const ScavTrap& other) :
	ClapTrap(other), gatekeeperMode(other.gatekeeperMode)
{
	std::cout << "ScavTrap copy constructor called\n";
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	ClapTrap::operator=(other);
	std::cout << "ScavTrap assignment operator called\n";
	gatekeeperMode = other.gatekeeperMode;
	return *this;
}

void ScavTrap::attack(const std::string& target)
{
	if (!isAlive() || !hasEnergy())
		return;
	std::cout << "ScavTrap " << name << " attacks " << target <<
		", causing " << attackDamage << " points of damage!\n";
	energyPoints--;
}

void ScavTrap::guardGate()
{
	if (!isAlive())
		return;
	gatekeeperMode = !gatekeeperMode;
	if (gatekeeperMode)
		std::cout << "ScavTrap " << name << " is now in gatekeeper mode.\n";
	else
		std::cout << "ScavTrap " << name << " is no longer in gatekeeper mode.\n";
}
