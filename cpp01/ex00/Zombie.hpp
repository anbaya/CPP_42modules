#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie {
private:
	std::string name;
public:
	void setName(std::string n);
	void announce( void );
	Zombie(std::string n);
	Zombie();
	~Zombie();
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif // !ZOMBIE_HPP