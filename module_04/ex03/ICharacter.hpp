#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include <string>
#include "AMateria.hpp"

class ICharacter
{
public:
	virtual ~ICharacter(void) {}
	virtual const std::string& getName(void) const = 0;
	virtual void equip(AMateria* m) = 0;
	virtual void unequip(unsigned int idx) = 0;
	virtual void use(unsigned int idx, const ICharacter& target) const = 0;
};

#endif
