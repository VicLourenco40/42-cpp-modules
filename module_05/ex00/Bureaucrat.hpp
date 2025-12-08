#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>

class Bureaucrat
{
private:
	static const int lowestGrade = 150;
	static const int highestGrade = 1;

	const std::string name;
	int grade;

	Bureaucrat(void);

	void setGrade(int grade);

public:
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat(const std::string& name, int grade);
	~Bureaucrat(void);

	Bureaucrat& operator=(const Bureaucrat& other);

	const std::string& getName(void) const;
	int getGrade(void) const;
	void incrementGrade(void);
	void decrementGrade(void);

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
