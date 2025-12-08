#include "Bureaucrat.hpp"
#include "Intern.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>

int main(void)
{
	std::srand(std::time(NULL));

	Bureaucrat bureaucrat("bureaucrat", 1);
	std::cout << bureaucrat << '\n';
	std::cout << '\n';

	Intern intern;

	AForm* fa = intern.makeForm("shrubbery creation", "home");
	bureaucrat.signForm(*fa);
	bureaucrat.executeForm(*fa);
	delete fa;
	std::cout << '\n';

	AForm* fb = intern.makeForm("robotomy request", "friend");
	bureaucrat.signForm(*fb);
	bureaucrat.executeForm(*fb);
	delete fb;
	std::cout << '\n';

	AForm* fc = intern.makeForm("presidential pardon", "heister");
	bureaucrat.signForm(*fc);
	bureaucrat.executeForm(*fc);
	delete fc;
	std::cout << '\n';

	intern.makeForm("high five request", "claptrap");
}
