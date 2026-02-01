#include "MateriaSource.hpp"
#include "AMateria.hpp"
#include <iostream>

MateriaSource::MateriaSource() {
	for (size_t i = 0; i < 4; i++) {
		this->materias[i] = NULL;
	}
}

MateriaSource::MateriaSource(const MateriaSource &other) {
	for (size_t i = 0; i < 4; i++) {
		this->materias[i] = other.materias[i] ? other.materias[i]->clone() : NULL;
	}
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other) {
	if (this != &other) {
		for (size_t i = 0; i < 4; i++) {
			if (this->materias[i])
				delete this->materias[i];
			this->materias[i] = other.materias[i] ? other.materias[i]->clone() : NULL;
		}
	}
	return *this;
}

MateriaSource::~MateriaSource() {
	for (size_t i = 0; i < 4; i++) {
		if (this->materias[i])
			delete this->materias[i];
	}
}

void MateriaSource::learnMateria(AMateria *materia) {
	if (!materia)
		return;

	for (size_t i = 0; i < 4; i++) {
		if (!this->materias[i]) {
			this->materias[i] = materia;
			return;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const &type) {
	for (size_t i = 0; i < 4; i++) {
		if (this->materias[i] && this->materias[i]->getType() == type)
			return this->materias[i]->clone();
	}
	return NULL;
}
