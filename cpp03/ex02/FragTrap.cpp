#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	std::cout << "FragTrap " << name << " default constructor is called" << std::endl;
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
};

FragTrap::~FragTrap(){
	std::cout << "FragTrap " << name << " destructor is called" << std::endl;
};

void FragTrap::highFivesGuys(){
	std::cout << "FragTrap " << name << " WSSAP GUYS HIGH FIVE !!" << std::endl;
}

void FragTrap::takeDamage(unsigned int amount){
	if (amount >= hitPoints)
	{
		hitPoints = 0;
		std::cout << "FragTrap " << name << " has been destroyed !!" << std::endl;
		std::cout << "current " << name << " hit points is " << hitPoints << std::endl;
	}
	else{
		hitPoints -= amount;
		std::cout << "FragTrap " << name << " has been damaged by " << amount << std::endl;
		std::cout << "current " << name << " hit points is " << hitPoints << std::endl;

		
	}
}

void FragTrap::beRepaired(unsigned int amount){
	if (energyPoints > 0 && hitPoints > 0)
	{
		energyPoints -= 1;
		hitPoints += amount;
		std::cout << "FragTrap " << name << " has been repaired by " << amount << std::endl;
		std::cout << "current " << name << " hit points is " << hitPoints << std::endl;
	}
	else
		std::cout << "FragTrap " << name << " need energy or hit points to be repaired " << std::endl;
}

void FragTrap::attack(const std::string& target){
	if (energyPoints > 0)
	{
		energyPoints -= 1;
		std::cout << "FragTrap " << name << " attacks " << target << " causing " 
		<< attackDamage << " of damage !!" << std::endl;
		std::cout << "current " << name << " energy points is " << energyPoints << std::endl;
	}
}