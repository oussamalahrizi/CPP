#include "Fixed.hpp"


Fixed::Fixed(const int value) : value(value << fractional_bits)
{
}

Fixed::Fixed(const float value) : value(roundf(value * (1 << fractional_bits)))
{
	std::cout << this << std::endl;
	std::cout << "float value : " << this->toFloat() << std::endl;
}


Fixed::Fixed() : value(0)
{
}

int Fixed::getRawBits() const
{
	return this->value;
}

void Fixed::setRawBits(int const raw)
{
	this->value = raw;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "operator" << std::endl;
    if (this != &other)
        value = other.value;
    return *this;
}

Fixed::Fixed(const Fixed &other) : value(other.value)
{
	std::cout << "copy" << std::endl;
	*this = other;
}

Fixed::~Fixed()
{
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

// compare

bool Fixed::operator<(const Fixed& other) const
{
	return (this->toFloat() < other.toFloat());
}
bool Fixed::operator<=(const Fixed& other) const
{
	return (this->toFloat() <= other.toFloat());
}
bool Fixed::operator>(const Fixed& other) const
{
	return (this->toFloat() > other.toFloat());
}
bool Fixed::operator>=(const Fixed& other) const
{
	return (this->toFloat() >= other.toFloat());
}
bool Fixed::operator==(const Fixed& other) const
{
	return (this->toFloat() == other.toFloat());
}

bool Fixed::operator!=(const Fixed& other) const
{
	return (this->toFloat() != other.toFloat());
}

// arithmetic

Fixed& Fixed::operator++()
{
	this->value++;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	operator++();
	return temp;
}

Fixed& Fixed::operator--()
{
	this->value--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	operator--();
	return temp;
}

Fixed& Fixed::min(Fixed& left, Fixed& right)
{
	return (left <= right ? left : right);
}

const Fixed& Fixed::min(const Fixed& left, const Fixed& right)
{
	return (left <= right ? left : right);
}

Fixed& Fixed::max(Fixed& left, Fixed& right)
{
	return (left >= right ? left : right);
}

const Fixed& Fixed::max(const Fixed& left, const Fixed& right)
{
	return (left >= right ? left : right);
}

Fixed Fixed::operator+(const Fixed& other) const
{
	return (Fixed(this->toFloat() + other.toFloat()));	
}

Fixed Fixed::operator-(const Fixed& other) const
{
	return (Fixed(this->toFloat() - other.toFloat()));	
}

float Fixed::operator*(const Fixed& other) const
{
	return (this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const
{
	return (Fixed(this->toFloat() / other.toFloat()));	
}