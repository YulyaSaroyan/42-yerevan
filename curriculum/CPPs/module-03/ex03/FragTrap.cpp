#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	std::cout << "FragTrap Parametrized constructor called!" << std::endl;

	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
}

// should not be called
FragTrap::FragTrap() {
	std::cout << "FragTrap Default constructor called!" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other) {
	std::cout << "FragTrap Copy constructor called!" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other) {
	std::cout << "FragTrap Copy assignment operator called!" << std::endl;
	if (this != &other)
		ClapTrap::operator=(other);
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap Destructor called!" << std::endl;
}

void FragTrap::attack(const std::string &target) {
	if (this->hitPoints == 0) {
		std::cout << "[attack]: FragTrap " << this->name << " is dead!" << std::endl;
		return;
	}

	if (this->energyPoints == 0) {
		std::cout << "[attack]: FragTrap " << this->name << " has no energy left!" << std::endl;
		return;
	}

	this->energyPoints--;
	std::cout << "FragTrap " << this->name
			  << " attacks " << target
			  << ", causing " << this->attackDamage
			  << " points of damage!" << std::endl;
}

void FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap " << name << " requests a high five! ✋" << std::endl;
}

