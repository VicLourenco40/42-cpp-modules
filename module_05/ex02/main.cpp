#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>

int main(void)
{
	std::srand(std::time(NULL));

	Bureaucrat a("a", 150);
	std::cout << a << '\n';

	Bureaucrat b("b", 1);
	std::cout << b << '\n';
	std::cout << '\n';

	ShrubberyCreationForm fa("home");
	std::cout << fa << '\n';

	a.executeForm(fa);
	b.executeForm(fa);
	a.signForm(fa);
	b.signForm(fa);
	std::cout << fa << '\n';
	a.executeForm(fa);
	b.executeForm(fa);
	std::cout << '\n';

	RobotomyRequestForm fb("friend");
	std::cout << fb << '\n';

	a.executeForm(fb);
	b.executeForm(fb);
	a.signForm(fb);
	b.signForm(fb);
	std::cout << fb << '\n';
	a.executeForm(fb);
	b.executeForm(fb);
	std::cout << '\n';

	PresidentialPardonForm fc("heister");
	std::cout << fc << '\n';

	a.executeForm(fc);
	b.executeForm(fc);
	a.signForm(fc);
	b.signForm(fc);
	std::cout << fc << '\n';
	a.executeForm(fc);
	b.executeForm(fc);
}
