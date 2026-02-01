#include "Animal.hpp"
#include <iostream>

Animal::Animal() : type("unknown") {
	std::cout << "Animal Default constructor called!" << std::endl;
}

Animal::Animal(const Animal &other) {
	std::cout << "Animal Copy constructor called!" << std::endl;

	*this = other;
}

Animal &Animal::operator=(const Animal &other) {
	std::cout << "Animal Copy assignment operator called!" << std::endl;

	if(this != &other) {
		this->type = other.type;
	}
	return *this;
}

Animal::~Animal() {
	std::cout << "Animal Destructor called!" << std::endl;
}

std::string Animal::getType() const {
	return this->type;
}
