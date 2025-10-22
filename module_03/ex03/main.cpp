#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap robot("D14M0ND-TP");
	std::string otherRobot = "CU5TM-TP";

	robot.whoAmI();
	robot.guardGate();
	robot.guardGate();
	robot.highFivesGuys();
	robot.attack(otherRobot);
	robot.takeDamage(50);
	robot.beRepaired(25);
	robot.takeDamage(50);
	robot.takeDamage(100);
	robot.whoAmI();
	robot.guardGate();
	robot.highFivesGuys();
	robot.attack(otherRobot);
	robot.beRepaired(25);
}
