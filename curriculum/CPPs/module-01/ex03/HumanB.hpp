#ifndef HUMAN_B_HPP
#define HUMAN_B_HPP

#include <string>
#include "Weapon.hpp"


class HumanB {
private:
	std::string name;
	Weapon *weapon;
public:
	HumanB(std::string name) : name(name), weapon(NULL) {};
	void attack() const;
	void setWeapon(Weapon &weapon);
};

#endif
