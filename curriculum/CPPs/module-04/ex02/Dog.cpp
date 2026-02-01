#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal() {
	std::cout << "Dog Default constructor called!" << std::endl;

	this->type = "Dog";
	this->brain = new Brain();
}

Dog::Dog(const Dog &other) : Animal(other) {
	std::cout << "Dog Copy constructor called!" << std::endl;

	this->brain = new Brain(*other.getBrain());
	this->type = other.getType();
}

Dog &Dog::operator=(const Dog &other) {
	std::cout << "Dog Copy assignment operator called!" << std::endl;

	if(this != &other) {
		Animal::operator=(other);
		*this->brain = *other.getBrain();
	}
	return *this;
}

Dog::~Dog() {
	std::cout << "Dog Destructor called!" << std::endl;

	delete this->brain;
}

void Dog::makeSound() const {
	std::cout << "Woof" << std::endl;
}

Brain *Dog::getBrain() const {
	return this->brain;
}
