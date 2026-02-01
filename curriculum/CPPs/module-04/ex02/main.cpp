#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

int main() {
	std::cout << std::endl << "===== MULTIPLE ANIMAL CREATION TESTS =====" << std::endl << std::endl;

	Animal *animals[10];
	for (size_t i = 0; i < 5; i++) {
		animals[i] = new Cat();
	}

	for (size_t i = 5; i < 10; i++) {
		animals[i] = new Dog();
	}

	for (size_t i = 0; i < 10; i++) {
		delete animals[i];
	}

	std::cout << "===== DEEP COPY TESTS =====" << std::endl;

	Cat originalCat;
	originalCat.getBrain()->setIdea(0, "Eat fish");

	Cat copiedCat = originalCat;
	copiedCat.getBrain()->setIdea(0, "Sleep");

	std::cout << "[TEST] Original Cat brain idea: "
			  << originalCat.getBrain()->getIdea(0) << std::endl;
	std::cout << "[TEST] Copied Cat brain idea: "
			  << copiedCat.getBrain()->getIdea(0) << std::endl;

	Dog originalDog;
	originalDog.getBrain()->setIdea(0, "Chase cats");

	Dog copiedDog;
	copiedDog = originalDog;
	copiedDog.getBrain()->setIdea(0, "Bark loudly");

	std::cout << "[TEST] Original Dog brain idea: "
			  << originalDog.getBrain()->getIdea(0) << std::endl;
	std::cout << "[TEST] Copied Dog brain idea: "
			  << copiedDog.getBrain()->getIdea(0) << std::endl;

	std::cout << "[INFO] Deep copy tests finished." << std::endl;

	std::cout << std::endl << "[INFO] Tests finished successfully." << std::endl;


	return 0;
}

