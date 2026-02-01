#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal() {
	std::cout << "Cat Default constructor called!" << std::endl;

	this->type = "Cat";
}

Cat::Cat(const Cat &other) : Animal(other) {
	std::cout << "Cat Copy constructor called!" << std::endl;

	*this = other;
}

Cat &Cat::operator=(const Cat &other) {
	std::cout << "Cat Copy assignment operator called!" << std::endl;

	if(this != &other) {
		Animal::operator=(other);
	}
	return *this;
}

Cat::~Cat() {
	std::cout << "Cat Destructor called!" << std::endl;
}

void Cat::makeSound() const {
	std::cout << "Mew" << std::endl;
}
