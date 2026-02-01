#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat() : WrongAnimal() {
	std::cout << "WrongCat Default constructor called!" << std::endl;

	this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other) {
	std::cout << "WrongCat Copy constructor called!" << std::endl;

	*this = other;
}

WrongCat &WrongCat::operator=(const WrongCat &other) {
	std::cout << "WrongCat Copy assignment operator called!" << std::endl;

	if(this != &other) {
		WrongAnimal::operator=(other);
	}
	return *this;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat Destructor called!" << std::endl;
}

void WrongCat::makeSound() const {
	std::cout << "Mew" << std::endl;
}
