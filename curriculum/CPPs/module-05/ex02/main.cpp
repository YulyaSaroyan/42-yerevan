#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
	try {
		Bureaucrat bob("Bob", 1);
		Bureaucrat alice("Alice", 150);

		ShrubberyCreationForm shrub("home");
		RobotomyRequestForm robot("Marvin");
		PresidentialPardonForm pardon("Ford");

		alice.executeForm(shrub); // should fail (not signed)
		shrub.beSigned(bob);      // Bob signs
		bob.executeForm(shrub);   // should succeed

		robot.beSigned(bob);
		bob.executeForm(robot);   // 50% chance success/failure

		pardon.beSigned(bob);
		bob.executeForm(pardon);  // succeed
	} catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	return 0;
}
