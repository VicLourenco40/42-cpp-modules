#ifndef FORM_HPP
#define FORM_HPP

#include <string>

class Bureaucrat;

class Form
{
private:
	const std::string name;
	const int signGrade;
	const int execGrade;
	bool isSigned;

public:
	Form(void);
	Form(const Form& other);
	Form(const std::string& name, int signGrade, int execGrade);
	~Form(void);

	Form& operator=(const Form& other);

	const std::string& getName(void) const;
	int getSignGrade(void) const;
	int getExecGrade(void) const;
	bool getIsSigned(void) const;
	void beSigned(const Bureaucrat& bureaucrat);

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

std::ostream& operator<<(std::ostream& os, const Form& obj);

#endif
