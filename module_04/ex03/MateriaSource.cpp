#include <iostream>
#include "MateriaSource.hpp"
#include "AMateria.hpp"

MateriaSource::MateriaSource(void) : materias()
{
	std::cout << "MateriaSource default constructor called\n";
}

MateriaSource::MateriaSource(const MateriaSource& other) : materias()
{
	std::cout << "MateriaSource copy constructor called\n";
	for (unsigned int i = 0; i < max_materias; ++i)
	{
		if (other.materias[i])
			materias[i] = other.materias[i]->clone();
	}
}

MateriaSource::~MateriaSource(void)
{
	std::cout << "MateriaSource destructor called\n";
	for (unsigned int i = 0; i < max_materias; ++i)
		delete materias[i];
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
	std::cout << "MateriaSource assignment operator called\n";
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

void MateriaSource::learnMateria(AMateria *const materia)
{
	if (!materia)
		return;
	for (unsigned int i = 0; i < max_materias; ++i)
	{
		if (materias[i])
			continue;
		materias[i] = materia;
		std::cout << materia->getType() << " learned in slot " << i << ".\n";
		return;
	}
	std::cout << "no empty slots to learn " << materia->getType() << ".\n";
}

AMateria* MateriaSource::createMateria(const std::string& type) const
{
	for (unsigned int i = 0; i < max_materias; ++i)
	{
		if (materias[i] && materias[i]->getType() == type)
			return materias[i]->clone();
	}
	return NULL;
}
