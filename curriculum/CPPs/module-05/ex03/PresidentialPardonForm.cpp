#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
	: AForm("PresidentialPardonForm", 25, 5), target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
	: AForm(other), target(other.target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
	AForm::operator=(other);
	target = other.target;
	return *this;
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const {
	AForm::canExecute(executor);

	std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
