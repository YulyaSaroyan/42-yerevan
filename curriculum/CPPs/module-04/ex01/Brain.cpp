#include "Brain.hpp"
#include <iostream>

Brain::Brain() {
	std::cout << "Brain Default constructor called!" << std::endl;
}

Brain::Brain(const Brain &other) {
	std::cout << "Brain Copy constructor called!" << std::endl;

	for (int i = 0; i < 100; ++i) {
		this->ideas[i] = other.getIdeas()[i];
	}
}

Brain &Brain::operator=(const Brain &other) {
	std::cout << "Brain Copy assignment operator called!" << std::endl;
	if (this != &other) {
		for (int i = 0; i < 100; ++i) {
			this->ideas[i] = other.getIdeas()[i];
		}
	}
	return *this;
}

Brain::~Brain() {
	std::cout << "Brain Destructor called!" << std::endl;
}

const std::string* Brain::getIdeas() const {
	return ideas;
}

const std::string Brain::getIdea(int index) const {
	return ideas[index];
}

std::string Brain::setIdea(int index, std::string value) {
	return ideas[index] = value;
}
