#include "HumanB.hpp"
#include <iostream>

void HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}

HumanB::HumanB(std::string name){
	this->name = name;
	this->weapon = 0; // nullptr in C++98: use 0
}

HumanB::~HumanB() {
}

void HumanB::attack() {
	if (this->weapon)
		std::cout << name << " attacks with their " << this->weapon->getType() << std::endl;
	else
		std::cout << name << " has no weapon" << std::endl;
}
