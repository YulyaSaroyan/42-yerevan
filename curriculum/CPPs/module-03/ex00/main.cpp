#include "ClapTrap.hpp"
#include <iostream>

int main() {
	std::cout << "===== BASIC CONSTRUCTION TESTS =====" << std::endl;
	ClapTrap claptrap1("CLTP1");
	ClapTrap claptrap2 = claptrap1;

	std::cout << "\n===== BASIC ACTION TESTS =====" << std::endl;
	claptrap1.attack("Target1");
	claptrap1.takeDamage(5);
	claptrap1.beRepaired(3);

	std::cout << "\n===== MULTIPLE ATTACKS UNTIL ENERGY DEPLETION =====" << std::endl;
	for (int i = 0; i < 8; ++i) {
		claptrap1.attack("EnergyDummy");
	}

	std::cout << "\n===== ATTACK AFTER ENERGY DEPLETED =====" << std::endl;
	claptrap1.attack("NoEnergyTarget");

	std::cout << "\n===== DAMAGE AND DEATH TEST =====" << std::endl;
	claptrap1.takeDamage(20);
	claptrap1.attack("AfterDeathTarget");
	claptrap1.beRepaired(5);

	std::cout << "\n===== REPAIR ENERGY CONSUMPTION TEST =====" << std::endl;
	ClapTrap healer("Healer");
	healer.beRepaired(5);
	healer.beRepaired(5);
	healer.beRepaired(5);
	healer.beRepaired(5);
	healer.beRepaired(5);

	std::cout << "\n===== SELF DAMAGE TEST =====" << std::endl;
	healer.takeDamage(0);
	healer.takeDamage(1000);

	std::cout << "\n===== LONG SEQUENCE MIXED ACTIONS =====" << std::endl;
	ClapTrap fighter("Fighter");
	fighter.attack("Enemy");
	fighter.takeDamage(3);
	fighter.beRepaired(2);
	fighter.attack("Enemy");
	fighter.takeDamage(8);
	fighter.beRepaired(10);
	fighter.attack("Enemy");

	std::cout << "\n===== COPY INDEPENDENCE TEST =====" << std::endl;
	ClapTrap original("Original");
	ClapTrap copy = original;
	original.takeDamage(5);
	copy.beRepaired(3);
}
