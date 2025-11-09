#include "Zombie.hpp"

int main()
{
	Zombie* z1 = newZombie("Zombie1");
	Zombie* z2 = newZombie("Zombie2");

	z1->announce();
	z2->announce();

	delete z1;
	delete z2;

	randomChump("RandomZombie");

	return 0;
}