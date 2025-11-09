#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name):name(name){
	std::cout << "ClapTrap " << name << " default constructor is called" << std::endl;
	hitPoints = 10;
	energyPoints = 10;
	attackDamage = 0;
};

ClapTrap::~ClapTrap(){
	std::cout << "ClapTrap " << name << " destructor is called" << std::endl;
};

void ClapTrap::takeDamage(unsigned int amount){
	if (amount >= hitPoints)
	{
		hitPoints = 0;
		std::cout << "ClapTrap " << name << " has been destroyed !!" << std::endl;
		std::cout << "current " << name << " hit points is " << hitPoints << std::endl;
	}
	else{
		hitPoints -= amount;
		std::cout << "ClapTrap " << name << " has been damaged by " << amount << std::endl;
		std::cout << "current " << name << " hit points is " << hitPoints << std::endl;

		
	}
}

void ClapTrap::beRepaired(unsigned int amount){
	if (energyPoints > 0 && hitPoints > 0)
	{
		energyPoints -= 1;
		hitPoints += amount;
		std::cout << "ClapTrap " << name << " has been repaired by " << amount << std::endl;
		std::cout << "current " << name << " hit points is " << hitPoints << std::endl;
	}
	else
		std::cout << "ClapTrap " << name << " need energy or hit points to be repaired " << std::endl;
}

void ClapTrap::attack(const std::string& target){
	if (energyPoints > 0)
	{
		energyPoints -= 1;
		std::cout << "ClapTrap " << name << " attacks " << target << " causing " 
		<< attackDamage << " of damage !!" << std::endl;
		std::cout << "current " << name << " energy points is " << energyPoints << std::endl;
	}
}