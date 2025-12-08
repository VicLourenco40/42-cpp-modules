#include "AForm.hpp"
#include "Bureaucrat.hpp"

#include <iostream>

AForm::AForm(void) :
	name("Unnamed"), target("None"),
	signGrade(Bureaucrat::lowestGrade), execGrade(Bureaucrat::lowestGrade),
	isSigned(false) {}

AForm::AForm(const AForm& other) :
	name(other.name), target(other.target),
	signGrade(other.signGrade), execGrade(other.execGrade),
	isSigned(other.isSigned) {}

AForm::AForm(const std::string& name, const std::string& target,
	const int signGrade, const int execGrade) :
	name(name), target(target),
	signGrade(signGrade), execGrade(execGrade),
	isSigned(false)
{
	if (signGrade > Bureaucrat::lowestGrade ||
		execGrade > Bureaucrat::lowestGrade)
		throw GradeTooLowException();
	if (signGrade < Bureaucrat::highestGrade ||
		execGrade < Bureaucrat::highestGrade)
		throw GradeTooHighException();
}

AForm::~AForm(void) {}

AForm& AForm::operator=(const AForm& other)
{
	isSigned = other.isSigned;
	return *this;
}

const std::string& AForm::getName(void) const
{
	return name;
}

const std::string& AForm::getTarget(void) const
{
	return target;
}

int AForm::getSignGrade(void) const
{
	return signGrade;
}

int AForm::getExecGrade(void) const
{
	return execGrade;
}

bool AForm::getIsSigned(void) const
{
	return isSigned;
}

void AForm::beSigned(const Bureaucrat& signer)
{
	if (signer.getGrade() > signGrade)
		throw GradeTooLowException();
	isSigned = true;
}

void AForm::execute(const Bureaucrat& executor) const
{
	if (!isSigned)
		throw FormNotSignedException();
	if (executor.getGrade() > execGrade)
		throw GradeTooLowException();
	beExecuted();
}

const char* AForm::GradeTooLowException::what(void) const throw()
{
	return "Grade too low";
}

const char* AForm::GradeTooHighException::what(void) const throw()
{
	return "Grade too high";
}

const char* AForm::FormNotSignedException::what(void) const throw()
{
	return "Form not signed";
}

std::ostream& operator<<(std::ostream& os, const AForm& obj)
{
	os << obj.getName()
		<< ", target " << obj.getTarget()
		<< ", sign grade " << obj.getSignGrade()
		<< ", exec grade " << obj.getExecGrade()
		<< ", signed " << obj.getIsSigned();
	return os;
}
