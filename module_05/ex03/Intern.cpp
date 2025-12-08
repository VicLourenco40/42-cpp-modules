#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#include <iostream>

Intern::Intern(void) {}

Intern::Intern(const Intern& other)
{
	(void)other;
}

Intern::~Intern(void) {}

Intern& Intern::operator=(const Intern& other)
{
	(void)other;
	return *this;
}

AForm* Intern::makeForm(
	const std::string& type, const std::string& target) const
{
	static const std::string types[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	static AForm* (* const funcs[3])(const std::string&) = {
		ShrubberyCreationForm::newForm,
		RobotomyRequestForm::newForm,
		PresidentialPardonForm::newForm
	};
	AForm* form;
	for (int i = 0; i < 3; i++)
	{
		if (type == types[i])
		{
			form = funcs[i](target);
			std::cout << "Intern creates " << *form << '\n';
			return form;
		}
	}
	std::cout << "Intern couldn't create form of invalid type " << type << '\n';
	return (NULL);
}
