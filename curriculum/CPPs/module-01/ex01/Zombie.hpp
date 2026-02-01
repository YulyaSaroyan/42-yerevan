#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie {
private:
	std::string name;
public:
	Zombie( std::string name ) : name(name) {};
	Zombie() {};
	~Zombie();
	void announce( void ) const;
	void setName( std::string name );
};

#endif
