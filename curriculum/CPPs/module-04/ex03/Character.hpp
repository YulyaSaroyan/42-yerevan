#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"
#include <string>

class Character : public ICharacter {
private:
	AMateria *inventory[4];
	std::string name;
	Character();
public:
	Character(const Character &other);
	Character(std::string const & name);
	Character &operator=(const Character &other);
	~Character();

	std::string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
	AMateria* getEquipmentByIndex(int index);
};

#endif
