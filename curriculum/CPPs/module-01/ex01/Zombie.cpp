#include <iostream>
#include "Zombie.hpp"

Zombie::~Zombie() {
	std::cout << this->name << std::endl;
}

void Zombie::announce( void ) const {
	std::cout << this->name + ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name) {
	this->name = name;
}
