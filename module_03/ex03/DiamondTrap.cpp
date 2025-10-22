#include <iostream>
#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : name("Robot")
{
	std::cout << "DiamondTrap default constructor called\n";
	ClapTrap::name = name + "_clap_name";
	hitPoints = FragTrap::hitPoints;
	energyPoints = ScavTrap::energyPoints;
	//energyPoints = 50;
	attackDamage = FragTrap::attackDamage;
}

DiamondTrap::DiamondTrap(const std::string& name) :
	ClapTrap(name + "_clap_name"), ScavTrap(name + "_clap_name"),
	FragTrap(name + "_clap_name"), name(name)
{
	std::cout << "DiamondTrap constructor called\n";
	hitPoints = FragTrap::hitPoints;
	energyPoints = ScavTrap::energyPoints;
	//energyPoints = 50;
	attackDamage = FragTrap::attackDamage;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) :
	ClapTrap(other), ScavTrap(other), FragTrap(other), name(other.name)
{
	std::cout << "DiamondTrap copy constructor called\n";
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
	ClapTrap::operator=(other);
	ScavTrap::operator=(other);
	FragTrap::operator=(other);
	std::cout << "DiamondTrap assignment operator called\n";
	name = other.name;
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called\n";
}

void DiamondTrap::whoAmI() const
{
	if (!isAlive())
		return;
	std::cout << "DiamondTrap name: " << name << '\n';
	std::cout << "ClapTrap name: " << ClapTrap::name << '\n';
}
