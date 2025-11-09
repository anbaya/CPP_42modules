#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(){
	ClapTrap a("rachid");
	ClapTrap b("khalid");
	ScavTrap c("robot");
	ScavTrap d("gpt");

	c.guardGate();
	d.guardGate();
	a.attack("khalid");
	b.takeDamage(0);
	b.attack("rachid");
	a.takeDamage(0);
	c.attack("rachit");
	a.takeDamage(20);
	d.attack("robot");
	c.takeDamage(20);
	c.beRepaired(20);
	a.beRepaired(5);
	b.beRepaired(5);
}