#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
	static const int signGrade = 25;
	static const int execGrade = 5;

	PresidentialPardonForm(void);

	void beExecuted(void) const;

public:
	PresidentialPardonForm(const PresidentialPardonForm& other);
	PresidentialPardonForm(const std::string& target);
	~PresidentialPardonForm(void);

	PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
};

#endif
