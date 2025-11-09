#ifndef HARL_HPP
#define HARL_HPP

#include <string>
#include <iostream>
#include <cstring>

class Harl{
	private:
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );
	public:
		void complain( std::string level, std::string from );
};

#endif // !HARL_HPP