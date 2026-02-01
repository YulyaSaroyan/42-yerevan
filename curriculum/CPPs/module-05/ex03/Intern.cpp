#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& other) {
	(void)other;
}

Intern::~Intern() {}

Intern& Intern::operator=(const Intern& other) {
	(void)other;
	return *this;
}

AForm* Intern::createShrubbery(const std::string& target) {
	return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomy(const std::string& target) {
	return new RobotomyRequestForm(target);
}

AForm* Intern::createPardon(const std::string& target) {
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) const {
	struct FormPair {
		std::string name;
		FormCreator create;
	};

	static FormPair forms[] = {
		{ "shrubbery creation", &Intern::createShrubbery },
		{ "robotomy request", &Intern::createRobotomy },
		{ "presidential pardon", &Intern::createPardon }
	};

	for (int i = 0; i < 3; ++i) {
		if (forms[i].name == formName) {
			std::cout << "Intern creates " << formName << std::endl;
			return forms[i].create(target);
		}
	}

	std::cout << "Error: Form \"" << formName << "\" does not exist." << std::endl;
	return NULL;
}
