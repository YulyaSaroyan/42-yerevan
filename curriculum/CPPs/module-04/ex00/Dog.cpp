#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal() {
	std::cout << "Dog Default constructor called!" << std::endl;

	this->type = "Dog";
}

Dog::Dog(const Dog &other) : Animal(other) {
	std::cout << "Dog Copy constructor called!" << std::endl;

	*this = other;
}

Dog &Dog::operator=(const Dog &other) {
	std::cout << "Dog Copy assignment operator called!" << std::endl;

	if(this != &other) {
		Animal::operator=(other);
	}
	return *this;
}

Dog::~Dog() {
	std::cout << "Dog Destructor called!" << std::endl;
}

void Dog::makeSound() const {
	std::cout << "Woof" << std::endl;
}
