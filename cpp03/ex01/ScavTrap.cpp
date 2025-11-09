#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	std::cout << "ScavTrap " << name << " default constructor is called" << std::endl;
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
};

ScavTrap::~ScavTrap(){
	std::cout << "ScavTrap " << name << " destructor is called" << std::endl;
};

void ScavTrap::guardGate(){
	std::cout << "ScavTrap " << name << " is now in Gate 'keeper mode activated'!" << std::endl;
}

void ScavTrap::takeDamage(unsigned int amount){
	if (amount >= hitPoints)
	{
		hitPoints = 0;
		std::cout << "ScavTrap " << name << " has been destroyed !!" << std::endl;
		std::cout << "current " << name << " hit points is " << hitPoints << std::endl;
	}
	else{
		hitPoints -= amount;
		std::cout << "ScavTrap " << name << " has been damaged by " << amount << std::endl;
		std::cout << "current " << name << " hit points is " << hitPoints << std::endl;

		
	}
}

void ScavTrap::beRepaired(unsigned int amount){
	if (energyPoints > 0 && hitPoints > 0)
	{
		energyPoints -= 1;
		hitPoints += amount;
		std::cout << "ScavTrap " << name << " has been repaired by " << amount << std::endl;
		std::cout << "current " << name << " hit points is " << hitPoints << std::endl;
	}
	else
		std::cout << "ScavTrap " << name << " need energy or hit points to be repaired " << std::endl;
}

void ScavTrap::attack(const std::string& target){
	if (energyPoints > 0)
	{
		energyPoints -= 1;
		std::cout << "ScavTrap " << name << " attacks " << target << " causing " 
		<< attackDamage << " of damage !!" << std::endl;
		std::cout << "current " << name << " energy points is " << energyPoints << std::endl;
	}
}