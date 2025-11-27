#include "Form.hpp"
#include "Bureaucrat.hpp"

#include <iostream>

Form::Form(void) : name("Unnamed"), signGrade(Bureaucrat::lowestGrade),
	execGrade(Bureaucrat::lowestGrade), isSigned(false) {}

Form::Form(const Form& other) : name(other.name), signGrade(other.signGrade),
	execGrade(other.execGrade), isSigned(other.isSigned) {}

Form::Form(const std::string& name, const int signGrade, const int execGrade) :
	name(name), signGrade(signGrade), execGrade(execGrade), isSigned(false)
{
	if (signGrade > Bureaucrat::lowestGrade ||
		execGrade > Bureaucrat::lowestGrade)
		throw GradeTooLowException();
	if (signGrade < Bureaucrat::highestGrade ||
		execGrade < Bureaucrat::highestGrade)
		throw GradeTooHighException();
}

Form::~Form(void) {}

Form& Form::operator=(const Form& other)
{
	isSigned = other.isSigned;
	return *this;
}

const std::string& Form::getName(void) const
{
	return name;
}

int Form::getSignGrade(void) const
{
	return signGrade;
}

int Form::getExecGrade(void) const
{
	return execGrade;
}

bool Form::getIsSigned(void) const
{
	return isSigned;
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > signGrade)
		throw GradeTooLowException();
	isSigned = true;
}

const char* Form::GradeTooLowException::what(void) const throw()
{
	return "Grade too low";
}

const char* Form::GradeTooHighException::what(void) const throw()
{
	return "Grade too high";
}

std::ostream& operator<<(std::ostream& os, const Form& obj)
{
	os << obj.getName()
		<< ", sign grade " << obj.getSignGrade()
		<< ", exec grade " << obj.getExecGrade()
		<< ", signed " << obj.getIsSigned();
	return os;
}
