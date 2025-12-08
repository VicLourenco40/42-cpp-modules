#include "RobotomyRequestForm.hpp"

#include <iostream>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(void) :
	AForm("robotomy request", "None", signGrade, execGrade) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) :
	AForm(other) {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) :
	AForm("robotomy request", target, signGrade, execGrade) {}

RobotomyRequestForm::~RobotomyRequestForm(void) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(
	const RobotomyRequestForm& other)
{
	AForm::operator=(other);
	return *this;
}

AForm* RobotomyRequestForm::newForm(const std::string& target)
{
	return new RobotomyRequestForm(target);
}

void RobotomyRequestForm::beExecuted(void) const
{
	if (std::rand() % 2)
		std::cout << getTarget() << " has been robotomized\n";
	else
		std::cout << getTarget() << " robotomy failed\n";
}
