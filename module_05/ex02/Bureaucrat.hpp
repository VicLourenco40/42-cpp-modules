#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>

class AForm;

class Bureaucrat
{
private:
	const std::string name;
	int grade;

	void setGrade(int grade);

public:
	static const int lowestGrade = 150;
	static const int highestGrade = 1;

	Bureaucrat(void);
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat(const std::string& name, int grade);
	~Bureaucrat(void);

	Bureaucrat& operator=(const Bureaucrat& other);

	const std::string& getName(void) const;
	int getGrade(void) const;
	void incrementGrade(void);
	void decrementGrade(void);
	void signForm(AForm& form) const;
	void executeForm(const AForm& form) const;

	class GradeTooLowException : public std::exception
	{
	public:
		const char* what(void) const throw();
	};

	class GradeTooHighException : public std::exception
	{
	public:
		const char* what(void) const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);

#endif
