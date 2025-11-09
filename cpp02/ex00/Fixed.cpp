#include "Fixed.hpp"

Fixed::Fixed(){
	this->_numValue = 0;
	std::cout << "default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& copy){
	this->_numValue = copy._numValue;
		std::cout << "copy constructor called" << std::endl;

}

Fixed& Fixed::operator=(const Fixed& other){
	if (this != &other)
		this->_numValue = other._numValue;
	std::cout << "Copy assignment operator called" << std::endl;
	return *this;
}

Fixed::~Fixed(){
	std::cout << "destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_numValue;
}

void Fixed::setRawBits(int const raw){
	std::cout << "setRawBits member function called" << std::endl;
	this->_numValue = raw;
}