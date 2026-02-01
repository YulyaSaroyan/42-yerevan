#include "Zombie.hpp"
#include "randomChump.hpp"
#include "newZombie.hpp"

int main () {
	randomChump("Hulk");

	Zombie* zombie = newZombie("Batman");
	zombie->announce();

	delete zombie;

	return 0;
}
