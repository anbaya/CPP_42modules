#include "Harl.hpp"


void Harl::debug( void ){
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info( void ){
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning( void ){
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error( void ){
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}	

void Harl::complain( std::string level, std::string from ){

	// this variable will hold the starting level of the filter
	int starting = 0;

	// array of levels
	char levels[][10] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	//find where the filter will start from
	while (std::strcmp(from.c_str(), levels[starting]))
		starting++;

	// array of pointers member functions
	void (Harl::*funcs[])( void ) = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};

	// call the member functions starting from the rghit level
	for (int i = starting; i < 4; i++)
	{
		if (std::strcmp(level.c_str(), levels[i]) == 0)
		{
			(this->*funcs[i])();
			return ;
		}
	}
}