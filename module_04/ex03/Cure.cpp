#include <iostream>
#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure(void) : AMateria("cure")
{
	std::cout << "Cure default constructor called\n";
}

Cure::Cure(const Cure& other) : AMateria(other)
{
	std::cout << "Cure copy constructor called\n";
}

Cure::~Cure(void)
{
	std::cout << "Cure destructor called\n";
}

Cure& Cure::operator=(const Cure& other)
{
	std::cout << "Cure assignment operator called\n";
	AMateria::operator=(other);
	return *this;
}

Cure* Cure::clone(void) const
{
	return new Cure(*this);
}

void Cure::use(const ICharacter& target) const
{
	std::cout << "* heals " << target.getName() << "'s wounds *\n";
}
