#include <iostream>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
	std::cout << "ClapTrap Parametrized constructor called!" << std::endl;
}

// should not be called
ClapTrap::ClapTrap(){
	std::cout << "ClapTrap Default constructor called!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) {
	std::cout << "ClapTrap Copy constructor called!" << std::endl;
	*this = other;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
	std::cout << "ClapTrap Copy assignment operator called!" << std::endl;
	if(this != &other) {
		this->name = other.name;
		this->hitPoints = other.hitPoints;
		this->energyPoints = other.energyPoints;
		this->attackDamage = other.attackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap Destructor called!" << std::endl;
}

void ClapTrap::attack(const std::string &target) {
	if (this->hitPoints == 0) {
		std::cout << "[attack]: ClapTrap " << this->name << " is dead!" << std::endl;
		return;
	}

	if (this->energyPoints == 0) {
		std::cout << "[attack]: ClapTrap " << this->name << " has no energy left!" << std::endl;
		return;
	}

	this->energyPoints--;

	std::cout << "ClapTrap " << this->name
				<< " attacks " << target
				<< ", causing " << this->attackDamage
				<< " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->hitPoints == 0) {
		std::cout << "[repair]: ClapTrap " << this->name << " is dead!" << std::endl;
		return;
	}

	if (this->energyPoints == 0) {
		std::cout << "[repair]: ClapTrap " << this->name << " has no energy left!" << std::endl;
		return;
	}

	this->hitPoints += amount;
	this->energyPoints--;

	std::cout << "ClapTrap " << this->name
			<< " is repaired with " << amount
			<< " points, " << "remaining HP: "
			<< this->hitPoints << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	this->hitPoints -= amount;
	if (this->hitPoints < 0) this->hitPoints = 0;
	std::cout << "ClapTrap " << this->name << " takes " << amount << " damage, "
			  << "remaining HP: " << this->hitPoints << std::endl;
}
