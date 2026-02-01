#include <iostream>
#include "HumanB.hpp"

void HumanB::attack() const {
	std::cout << name << " attacks with " << weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon) {
	this->weapon = &weapon;
}
