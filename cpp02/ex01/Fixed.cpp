#include "Fixed.hpp"


Fixed::Fixed(const int value) : value(value << fractional_bits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value) : value(roundf(value * (1 << fractional_bits)))
{
	std::cout << "Float constructor called" << std::endl;
}


Fixed::Fixed() : value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->value;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->value = raw;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        value = other.value;
    return *this;
}

Fixed::Fixed(const Fixed &other) : value(other.value)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}


float Fixed::toFloat() const
{
	return ((float) value / (1 << fractional_bits));
}

int Fixed::toInt() const
{
	return (value >> fractional_bits);
}

std::ostream& operator<<(std::ostream& stream,const  Fixed& other)
{
	stream << other.toFloat();
	return (stream);
}