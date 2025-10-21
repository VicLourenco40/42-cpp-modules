#include "ScavTrap.hpp"

int main()
{
	ScavTrap robot("SC4V-TP");
	std::string otherRobot = "CU5TM-TP";

	robot.guardGate();
	robot.guardGate();
	robot.attack(otherRobot);
	robot.takeDamage(50);
	robot.beRepaired(25);
	robot.takeDamage(50);
	robot.takeDamage(100);
	robot.attack(otherRobot);
	robot.beRepaired(25);
	robot.guardGate();
}
