#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), name(name) {
	std::cout << "DiamondTrap Parametrized constructor called!" << std::endl;

	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 30;
}

// should not be called
DiamondTrap::DiamondTrap() {
	std::cout << "DiamondTrap Default constructor called!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other), ScavTrap(other), FragTrap(other), name(other.name) {
	std::cout << "DiamondTrap Copy constructor called!" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other) {
	std::cout << "DiamondTrap Copy assignment operator called!" << std::endl;
	if (this != &other) {
		ClapTrap::operator=(other);
		this->name = other.name;
	}
	return *this;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap Destructor called!" << std::endl;
}

void DiamondTrap::attack(const std::string &target) {
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() {
	std::cout << "DiamondTrap name: " << this->name
			  << ", ClapTrap name: " << ClapTrap::name << std::endl;
}
