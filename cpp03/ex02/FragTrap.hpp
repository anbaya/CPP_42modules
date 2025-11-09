#pragma once

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap{
	public:
	FragTrap(std::string name);
	~FragTrap();
	void highFivesGuys(void);
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};