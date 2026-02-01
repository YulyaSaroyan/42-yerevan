#include "Bureaucrat.hpp"

int main()
{
	try {
		Bureaucrat a("Alice", 1);
		Bureaucrat b("Bob", 150);

		std::cout << a << std::endl;
		std::cout << b << std::endl;

		a.increment(); // should throw
	}
	catch (std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	try {
		Bureaucrat bad("X", 200); // throws on constructor
	}
	catch (std::exception& e) {
		std::cout << "Constructor exception: " << e.what() << std::endl;
	}

	return 0;
}
