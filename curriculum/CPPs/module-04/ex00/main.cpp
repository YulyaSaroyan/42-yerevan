#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"
#include <iostream>

int main() {
	std::cout << "===== ANIMAL TESTS =====" << std::endl << std::endl;

	const Animal* meta = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	std::cout << "[INFO] Dog type: " << dog->getType() << std::endl;
	std::cout << "[INFO] Cat type: " << cat->getType() << std::endl << std::endl;

	std::cout << "[ACTION] Cat makes a sound: ";
	cat->makeSound();

	std::cout << "[ACTION] Dog makes a sound: ";
	dog->makeSound();

	std::cout << "[ACTION] Animal makes a sound: ";
	meta->makeSound();

	delete meta;
	delete dog;
	delete cat;

	std::cout << std::endl << "===== WRONG ANIMAL TESTS =====" << std::endl << std::endl;

	const WrongAnimal* wrongMeta = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();

	std::cout << "[INFO] WrongCat type: " << wrongCat->getType() << std::endl << std::endl;

	std::cout << "[ACTION] WrongCat makes a sound: ";
	wrongCat->makeSound();

	std::cout << "[ACTION] WrongAnimal makes a sound: ";
	wrongMeta->makeSound();

	delete wrongMeta;
	delete wrongCat;

	std::cout << std::endl << "[INFO] Tests finished successfully." << std::endl;

	return 0;
}
