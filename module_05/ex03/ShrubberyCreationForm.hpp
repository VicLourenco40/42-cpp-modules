#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:
	static const int signGrade = 145;
	static const int execGrade = 137;

	ShrubberyCreationForm(void);

	void beExecuted(void) const;

public:
	ShrubberyCreationForm(const ShrubberyCreationForm& other);
	ShrubberyCreationForm(const std::string& target);
	~ShrubberyCreationForm(void);

	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);

	static AForm* newForm(const std::string& target);
};

#endif
