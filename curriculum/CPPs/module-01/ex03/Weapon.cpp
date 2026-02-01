#include "Weapon.hpp"

std::string Weapon::getType() const {
	return type;
}

void Weapon::setType(std::string type) {
	this->type = type;
}
