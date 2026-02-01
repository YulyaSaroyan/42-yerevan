#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm("ShrubberyCreationForm", 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
	: AForm(other), target(other.target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
	if (this != &other) {
		AForm::operator=(other);
		this->target = other.target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
	AForm::canExecute(executor);

	std::ofstream file((this->target + "_shrubbery").c_str());
	if (!file) return;

	file << "      /\\\n";
	file << "     /  \\\n";
	file << "    /++++\\\n";
	file << "   /  ()  \\\n";
	file << "  /        \\\n";
	file << " /~`~`~`~`~\\\n";
	file << "      ||\n";
	file << "      ||\n";

	file.close();
}
