#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class HumanA
{
	const std::string name;
	Weapon& weapon;

public:
	HumanA(const std::string& name, Weapon& weapon);
	void setWeapon(Weapon& newWeapon);
	void attack() const;
};

#endif
