#pragma once

#include <iostream>

class Fixed{
	private:
		int _numValue;
		static const int _fBits = 8;
	public:
		Fixed();
		Fixed(const Fixed& copy);
		Fixed& operator=(const Fixed& other);
		~Fixed();
		int getRawBits( void ) const;
		void setRawBits( int const raw );
};