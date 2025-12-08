#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"

#include <string>

class Intern
{
public:
	Intern(void);
	Intern(const Intern& other);
	~Intern(void);

	Intern& operator=(const Intern& other);

	AForm* makeForm(const std::string& form, const std::string& target) const;
};

#endif
