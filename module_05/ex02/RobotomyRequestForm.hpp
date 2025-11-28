#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
	static const int signGrade = 72;
	static const int execGrade = 45;

	RobotomyRequestForm(void);

	void beExecuted(void) const;

public:
	RobotomyRequestForm(const RobotomyRequestForm& other);
	RobotomyRequestForm(const std::string& target);
	~RobotomyRequestForm(void);

	RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
};

#endif
