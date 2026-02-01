#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main() {
	ScavTrap scav1("Guardian1");
	ScavTrap scav2 = scav1;
	ScavTrap scav3 = scav1;

	std::cout << "\n----- Basic attack & guard -----" << std::endl;
	scav1.attack("EnemyA");
	scav1.guardGate();

	std::cout << "\n----- Multiple attacks until energy depletion -----" << std::endl;
	for (int i = 0; i < 49; ++i) {
		scav1.attack("Dummy");
	}
	scav1.attack("AfterEnergyDepletion");

	std::cout << "\n----- Damage & repair tests -----" << std::endl;
	scav1.takeDamage(40);
	scav1.beRepaired(20);
	scav1.takeDamage(200);
	scav1.attack("AfterDeath");
	scav1.beRepaired(50);

	std::cout << "\n----- Copy independence for ScavTrap -----" << std::endl;
	scav2.takeDamage(10);
	scav3.beRepaired(5);

	std::cout << "\n===== SCAVTRAP GUARD MODE STRESS TEST =====" << std::endl;
	for (int i = 0; i < 3; ++i) {
		scav3.guardGate();
	}

	std::cout << "\n===== SCAVTRAP EDGE CASES =====" << std::endl;
	scav3.takeDamage(0);
	scav3.beRepaired(0);

	std::cout << "\n===== DESTRUCTOR TEST WITH DYNAMIC ALLOCATION (NEW) =====" << std::endl;
	ClapTrap *clapTrap = new ScavTrap("child");
	delete clapTrap;
}
