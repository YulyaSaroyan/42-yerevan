#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string name) {
	this->name = name;
}

Zombie::~Zombie() {
	std::cout << this->name << std::endl;
}

void Zombie::announce( void ) const {
	std::cout << this->name + ": BraiiiiiiinnnzzzZ..." << std::endl;
}

