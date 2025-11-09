#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(){
	ClapTrap a("rachid");
	ClapTrap b("khalid");
	ScavTrap c("robot");
	ScavTrap d("gpt");
	FragTrap e("deepseek");
	FragTrap f("claude");

	c.guardGate();
	d.guardGate();
	e.highFivesGuys();
	f.highFivesGuys();
	a.attack("khalid");
	b.takeDamage(0);
	b.attack("rachid");
	a.takeDamage(0);
	c.attack("rachit");
	a.takeDamage(20);
	d.attack("robot");
	c.takeDamage(20);
	c.beRepaired(20);
	e.attack("khalid");
	b.takeDamage(30);
	a.beRepaired(5);
	b.beRepaired(5);
}