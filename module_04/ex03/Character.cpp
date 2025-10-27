#include <iostream>
#include "Character.hpp"

Character::Character(void) : name("Unnamed"), materias()
{
	std::cout << "Character default constructor called\n";
}

Character::Character(const std::string& name) : name(name), materias()
{
	std::cout << "Character constructor called\n";
}

Character::Character(const Character& other) : name(other.name), materias()
{
	std::cout << "Character copy constructor called\n";
	for (unsigned int i = 0; i < max_materias; ++i)
	{
		if (other.materias[i])
			materias[i] = other.materias[i]->clone();
	}
}

Character::~Character(void)
{
	std::cout << "Character destructor called\n";
	for (unsigned int i = 0; i < max_materias; ++i)
		delete materias[i];
}

Character& Character::operator=(const Character& other)
{
	std::cout << "Character assignment operator called\n";
	name = other.name;
	for (unsigned int i = 0; i < max_materias; ++i)
	{
		delete materias[i];
		if (other.materias[i])
			materias[i] = other.materias[i]->clone();
		else
			materias[i] = NULL;
	}
	return *this;
}

const std::string& Character::getName(void) const
{
	return name;
}

void Character::equip(AMateria* materia)
{
	if (!materia)
		return;
	for (unsigned int i = 0; i < max_materias; ++i)
	{
		if (materias[i])
			continue;
		materias[i] = materia;
		std::cout << materia->getType() << " equipped in " << name
			<< "'s slot " << i << ".\n";
		return;
	}
	std::cout << name << " has no empty slots to equip "
		<< materia->getType() << ".\n";
}

void Character::unequip(const unsigned int id)
{
	if (id >= max_materias)
		return;
	std::cout << materias[id]->getType() << " unequipped from " << name
		<< "'s slot " << id << ".\n";
	materias[id] = NULL;
}

void Character::use(const unsigned int id, const ICharacter& target) const
{
	if (id >= max_materias || !materias[id])
		return;
	materias[id]->use(target);
}
