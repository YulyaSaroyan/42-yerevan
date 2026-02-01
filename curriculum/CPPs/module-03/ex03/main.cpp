#include <iostream>
#include "DiamondTrap.hpp"

int main() {
	std::cout << "\n=== Creating DiamondTrap objects ===\n";
	DiamondTrap d1("Diamondy");
	DiamondTrap d2("Shiny");

	std::cout << "\n=== Testing whoAmI() ===\n";
	d1.whoAmI();
	d2.whoAmI();

	std::cout << "\n=== Testing attacks ===\n";
	d1.attack("Enemy1");
	d2.attack("Enemy2");

	std::cout << "\n=== Testing ScavTrap and FragTrap abilities ===\n";
	d1.guardGate();
	d1.highFivesGuys();

	std::cout << "\n=== Testing hitPoints and damage ===\n";
	d1.takeDamage(30);
	d1.beRepaired(20);

	std::cout << "\n=== Copy constructor test ===\n";
	DiamondTrap d3 = d1;
	d3.whoAmI();
	d3.attack("CopyTarget");

	std::cout << "\n=== Assignment operator test ===\n";
	d2 = d1;
	d2.whoAmI();
	d2.attack("AssignedTarget");

	std::cout << "\n=== Testing multiple attacks ===\n";
	for (int i = 0; i < 49; i++)
		d1.attack("SpamAttack");

	std::cout << "\n=== End of tests ===\n";

	return 0;
}
