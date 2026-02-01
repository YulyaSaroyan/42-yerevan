#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria() {}

AMateria::AMateria(std::string const & type) : type(type) {}

AMateria::AMateria(const AMateria &other) {
	*this = other;
}

AMateria &AMateria::operator=(const AMateria &other) {
	if(this != &other) {
		this->type = other.type;
	}
	return *this;
}

AMateria::~AMateria() {}

void AMateria::use(ICharacter& target) {
	std::cout << this->getType() + " is used on " << target.getName() << std::endl;
}

std::string const & AMateria::getType() const {
	return this->type;
}
