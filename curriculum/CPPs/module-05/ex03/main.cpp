#include "Intern.hpp"

int main() {
	Intern intern;

	AForm* f1 = intern.makeForm("shrubbery creation", "home");
	AForm* f2 = intern.makeForm("robotomy request", "Marvin");
	AForm* f3 = intern.makeForm("presidential pardon", "Ford");
	AForm* f4 = intern.makeForm("unknown form", "target");

	delete f1;
	delete f2;
	delete f3;
	delete f4;

	return 0;
}
