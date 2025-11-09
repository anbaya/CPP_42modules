#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon {
	private:
		std::string type;
	public:
		Weapon(std::string weaponType);
		Weapon();
		~Weapon();
		void setType(std::string weaponType);
		std::string getType() const;
};


#endif // !WEAPON_HPP