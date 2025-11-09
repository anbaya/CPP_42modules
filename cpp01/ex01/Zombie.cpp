#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string name) {
	this->name = name;
    std::cout << this->name << " created." << std::endl;
}

Zombie::Zombie() {
	
}

Zombie::~Zombie() {
    std::cout << this->name << " destroyed." << std::endl;
}

void Zombie::announce(){
    std::cout << this->name << ": Braiiiiiiinnnssss..." << std::endl;
}

void Zombie::stName(std::string name) {
	this->name = name;
}