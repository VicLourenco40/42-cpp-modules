#include "Bureaucrat.hpp"
#include "AForm.hpp"

#include <iostream>

Bureaucrat::Bureaucrat(void) :
	name("Unnamed"), grade(lowestGrade) {}

Bureaucrat::Bureaucrat(const Bureaucrat& other) :
	name(other.name), grade(other.grade) {}

Bureaucrat::Bureaucrat(const std::string& name, const int grade) :
	name(name)
{
	setGrade(grade);
}

Bureaucrat::~Bureaucrat(void) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	grade = other.grade;
	return *this;
};

const std::string& Bureaucrat::getName(void) const
{
	return name;
}

int Bureaucrat::getGrade(void) const
{
	return grade;
}

void Bureaucrat::setGrade(const int grade)
{
	if (grade > lowestGrade)
		throw GradeTooLowException();
	if (grade < highestGrade)
		throw GradeTooHighException();
	this->grade = grade;
}

void Bureaucrat::incrementGrade(void)
{
	setGrade(this->grade - 1);
}

void Bureaucrat::decrementGrade(void)
{
	setGrade(this->grade + 1);
}

void Bureaucrat::signForm(AForm& form) const
{
	try
	{
		form.beSigned(*this);
		std::cout << name << " signed " << form.getName() << '\n';
	}
	catch (const std::exception& e)
	{
		std::cout << name << " couldn't sign " << form.getName()
			<< " because: " << e.what() << '\n';
	}
}

void Bureaucrat::executeForm(const AForm& form) const
{
	try
	{
		form.execute(*this);
		std::cout << name << " executed " << form.getName() << '\n';
	}
	catch (const std::exception& e)
	{
		std::cout << name << " couldn't execute " << form.getName()
			<< " because: " << e.what() << '\n';
	}
}

const char* Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return "Grade too low";
}

const char* Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return "Grade too high";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj)
{
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade();
	return os;
}
