#include "Character.hpp"
#include <iostream>

// should never be called
Character::Character() {}

Character::Character(std::string const & name) : name(name) {
	for (int i = 0; i < 4; i++) {
		this->inventory[i] = NULL;
	}
}

Character::Character(const Character &other) {
	this->name = other.getName();
	for (int i = 0; i < 4; i++) {
		this->inventory[i] = other.inventory[i] ? other.inventory[i]->clone() : NULL;
	}
}

Character &Character::operator=(const Character &other) {
	if(this != &other) {
		this->name = other.getName();
		for (int i = 0; i < 4; i++) {
			if (this->inventory[i])
				delete this->inventory[i];
			this->inventory[i] = other.inventory[i] ? other.inventory[i]->clone() : NULL;
		}
	}
	return *this;
}

Character::~Character() {
	for (int i = 0; i < 4; i++) {
		if (this->inventory[i])
			delete this->inventory[i];
	}
}

void Character::equip(AMateria* m) {
	if (!m)
		return;
	for (int i = 0; i < 4; i++) {
		if (this->inventory[i]) continue;
		this->inventory[i] = m;
		break;
	}
}

void Character::unequip(int idx) {
	if (!(idx >= 0 && idx <= 3))
		return;
	if (this->inventory[idx])
		this->inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) {
	if (!(idx >= 0 && idx <= 3))
		return;
	if (this->inventory[idx])
		this->inventory[idx]->use(target);
}

std::string const & Character::getName() const {
	return this->name;
}

AMateria *Character::getEquipmentByIndex(int index) {
	if (!(index >= 0 && index <= 3))
		return NULL;
	return this->inventory[index];
}
