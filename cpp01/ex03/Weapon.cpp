#include "Weapon.hpp"

Weapon::Weapon(std::string weaponType){
	this->type = weaponType;
}

Weapon::Weapon(){
	this->type = "";
}

Weapon::~Weapon() {
}

void Weapon::setType(std::string weaponType) {
	this->type = weaponType;
}

std::string Weapon::getType() const {
	return this->type;
}
