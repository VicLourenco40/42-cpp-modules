#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	FragTrap robot("FR4G-TP");
	std::string otherRobot = "CU5TM-TP";

	robot.highFivesGuys();
	robot.attack(otherRobot);
	robot.takeDamage(50);
	robot.beRepaired(25);
	robot.takeDamage(50);
	robot.takeDamage(100);
	robot.attack(otherRobot);
	robot.beRepaired(25);
	robot.highFivesGuys();
}
