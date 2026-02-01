#include "Zombie.hpp"
#include "zombieHorde.hpp"

int main () {
	Zombie* zombies = zombieHorde(3, "Superman");

	if (!zombies)
		return 0;

	for (size_t i = 0; i < 3; i++) {
		zombies[i].announce();
	}

	delete[] zombies;

	return 0;
}
