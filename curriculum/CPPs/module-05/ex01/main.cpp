#include "Bureaucrat.hpp"

int main()
{
	std::cout << "===== TEST 1: CREATE FORMS =====" << std::endl;
	try {
		Form f1("Easy", 100, 50);
		std::cout << f1 << std::endl;

		// grade too high
		Form f2("InvalidHigh", 0, 20);
	}
	catch (std::exception& e) {
		std::cout << "Caught exception: " << e.what() << "\n\n";
	}

	try {
		// grade too low
		Form f3("InvalidLow", 200, 20);
	}
	catch (std::exception& e) {
		std::cout << "Caught exception: " << e.what() << "\n\n";
	}

	std::cout << "===== TEST 2: SIGNING FORMS =====" << std::endl;

	Bureaucrat alice("Alice", 50);
	Bureaucrat charlie("Charlie", 140);

	Form tax("TaxForm", 100, 50);
	Form secret("SecretForm", 10, 5);

	// Expected: success
	alice.signForm(tax);

	// Expected: fail (grade too low)
	charlie.signForm(tax);

	// Expected: fail (Alice not high enough)
	alice.signForm(secret);

	// Expected: fail (Charlie MUCH too low)
	charlie.signForm(secret);

	std::cout << "\n===== TEST 3: DIRECT beSigned() CALLS =====" << std::endl;

	try {
		secret.beSigned(alice);  // Alice grade 50 cannot sign grade 10 → throw
	}
	catch (std::exception& e) {
		std::cout << "Caught exception: " << e.what() << std::endl;
	}

	try {
		Form high("HighSecurity", 1, 1);
		Bureaucrat chief("Chief", 1);
		high.beSigned(chief);     // Should work
		std::cout << "Form signed directly\n";
	}
	catch (std::exception& e) {
		std::cout << "Caught exception: " << e.what() << std::endl;
	}

	std::cout << "\n===== END OF TESTS =====" << std::endl;

	return 0;
}
