#include "ClapTrap.hpp"

int main(){
	ClapTrap a("rachid");
	ClapTrap b("khalid");

	a.attack("khalid");
	b.takeDamage(0);
	b.attack("rachid");
	a.takeDamage(0);
	a.beRepaired(5);
	b.beRepaired(5);
}