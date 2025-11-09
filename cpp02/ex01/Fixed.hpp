#pragma once

#include <iostream>
#include <cmath>

class Fixed{
	private:
		int _numValue;
		static const int _fBits = 8;
	public:
		Fixed();
		Fixed(const int num);
		Fixed(const float num);
		Fixed(const Fixed& copy);
		Fixed& operator=(const Fixed& other);
		~Fixed();
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		int toInt( void ) const;
		float toFloat( void ) const;

	};
	
std::ostream &operator<<(std::ostream &out, const Fixed &fixed);