#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>

class Bureaucrat;

class AForm
{
private:
	const std::string name;
	const std::string target;
	const int signGrade;
	const int execGrade;
	bool isSigned;

	AForm(void);

	virtual void beExecuted(void) const = 0;

public:
	AForm(const AForm& other);
	AForm(const std::string& name, const std::string& target,
		int signGrade, int execGrade);
	virtual ~AForm(void);

	AForm& operator=(const AForm& other);

	const std::string& getName(void) const;
	const std::string& getTarget(void) const;
	int getSignGrade(void) const;
	int getExecGrade(void) const;
	bool getIsSigned(void) const;
	void beSigned(const Bureaucrat& signer);
	void execute(const Bureaucrat& executor) const;

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

	class FormNotSignedException : public std::exception
	{
	public:
		const char* what(void) const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const AForm& obj);

#endif
