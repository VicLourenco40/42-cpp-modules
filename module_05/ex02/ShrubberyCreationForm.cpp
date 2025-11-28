#include "ShrubberyCreationForm.hpp"

#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(void) :
	AForm("shrubbery creation", "None", signGrade, execGrade) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) :
	AForm(other) {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) :
	AForm("shrubbery creation", target, signGrade, execGrade) {}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(
	const ShrubberyCreationForm& other)
{
	AForm::operator=(other);
	return *this;
}

void ShrubberyCreationForm::beExecuted(void) const
{
	std::ofstream f((getTarget() + "_shrubbery").c_str());
	if (!f.is_open())
		return;

	// https://asciiart.website/art/5030
	f << "  .-'- -.\n"
	  << " (       )\n"
	  << "(  ,      )\n"
	  << " ( \\'./  .'\n"
	  << "  '-| |-'\n"
	  << "jgs | |\n"
	  << ",,,,|.|,,,\n";

	f.close();
}
