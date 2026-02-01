#include "Zombie.hpp"
#include "newZombie.hpp"

void randomChump( std::string name ) {
	Zombie zombie(name);

	zombie.announce();
}
