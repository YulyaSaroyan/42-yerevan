#include <iostream>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main() {
	std::cout << "\n=== Creating ClapTrap ===\n";
	ClapTrap clap("Clappy");
	clap.attack("target");
	clap.takeDamage(5);
	clap.beRepaired(3);
	std::cout << std::endl;

	std::cout << "=== Creating ScavTrap ===\n";
	ScavTrap scav("Scavy");
	scav.attack("enemy1");
	scav.takeDamage(30);
	scav.beRepaired(10);
	scav.guardGate();
	std::cout << std::endl;

	std::cout << "=== Creating FragTrap ===\n";
	FragTrap frag("Fraggy");
	frag.attack("enemy2");
	frag.takeDamage(50);
	frag.beRepaired(25);
	frag.highFivesGuys();
	std::cout << std::endl;

	std::cout << "=== Polymorphism check ===\n";
	ClapTrap *ptr = new FragTrap("Polymorph");
	ptr->attack("Boss");
	delete ptr;
	std::cout << std::endl;

	std::cout << "=== All tests complete ===\n";
	return 0;
}
