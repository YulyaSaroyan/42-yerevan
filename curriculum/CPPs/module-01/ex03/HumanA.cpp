#include <iostream>
#include "HumanA.hpp"

void HumanA::attack() const {
	std::cout << name << " attacks with " << weapon.getType() << std::endl;
}
