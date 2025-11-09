#include "Zombie.hpp"

void	Zombie::setName(std::string n) {
	name = n;
}

void	Zombie::announce( void ) {
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(std::string n) {
	setName(n);
}

Zombie::Zombie() {
	setName("Unnamed");
}

Zombie::~Zombie() {
	std::cout << name << " is destroyed." << std::endl;
}