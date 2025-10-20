#include "ClapTrap.hpp"

int main()
{
	ClapTrap robot("CL4P-TP");
	std::string otherRobot = "CU5TM-TP";

	robot.attack(otherRobot);
	robot.takeDamage(5);
	robot.beRepaired(1);
	robot.takeDamage(10);
	robot.attack(otherRobot);
	robot.beRepaired(1);
}
