#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm("RobotomyRequestForm", 72, 45), target(target)
{
	std::srand(std::time(NULL));
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: AForm(other), target(other.target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	AForm::operator=(other);
	target = other.target;
	return *this;
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
	AForm::canExecute(executor);

	std::cout << "Brrrrr... drilling noises..." << std::endl;
	if (std::rand() % 2) {
		std::cout << target << " has been robotomized successfully!" << std::endl;
	} else {
		std::cout << "Robotomy failed on " << target << "!" << std::endl;
	}
}
