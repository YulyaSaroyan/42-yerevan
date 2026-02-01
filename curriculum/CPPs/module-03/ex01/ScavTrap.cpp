#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	std::cout << "ScavTrap Parametrized constructor called!" << std::endl;

	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
}

// should not be called
ScavTrap::ScavTrap() {
	std::cout << "ScavTrap Default constructor called!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) {
	std::cout << "ScavTrap Copy constructor called!" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
	std::cout << "ScavTrap Copy assignment operator called!" << std::endl;
	if (this != &other)
		ClapTrap::operator=(other);
	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap Destructor called!" << std::endl;
}

void ScavTrap::attack(const std::string &target) {
	if (this->hitPoints == 0) {
		std::cout << "[attack]: ScavTrap " << this->name << " is dead!" << std::endl;
		return;
	}

	if (this->energyPoints == 0) {
		std::cout << "[attack]: ScavTrap " << this->name << " has no energy left!" << std::endl;
		return;
	}

	this->energyPoints--;
	std::cout << "ScavTrap " << this->name
			  << " attacks " << target
			  << ", causing " << this->attackDamage
			  << " points of damage!" << std::endl;
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap is now in Gate Keeper mode!" << std::endl;
}
