#include "PresidentialPardonForm.hpp"

#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(void) :
	AForm("presidential pardon", "None", signGrade, execGrade) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) :
	AForm(other) {}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) :
	AForm("presidential pardon", target, signGrade, execGrade) {}

PresidentialPardonForm::~PresidentialPardonForm(void) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(
	const PresidentialPardonForm& other)
{
	AForm::operator=(other);
	return *this;
}

AForm* PresidentialPardonForm::newForm(const std::string& target)
{
	return new PresidentialPardonForm(target);
}

void PresidentialPardonForm::beExecuted(void) const
{
	std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox\n";
}
