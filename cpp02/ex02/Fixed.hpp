#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
    private:
        int value;
        static const int fractional_bits = 8;
    public:
        // constructors
        Fixed();
        Fixed(const Fixed &other);
        Fixed(const int value);
        Fixed(const float value);
        ~Fixed();

        // assignement operator
        Fixed& operator=(const Fixed& other);
        // compare
        bool operator<(const Fixed& other) const;
        bool operator<=(const Fixed& other) const;
        bool operator>(const Fixed& other) const;
        bool operator>=(const Fixed& other) const;
        bool operator==(const Fixed& other) const;
        bool operator!=(const Fixed& other) const;

        // inrement / decmrement
        Fixed& operator++();
        Fixed operator++(int);
        Fixed& operator--();
        Fixed operator--(int);

        // arithmetic
        Fixed operator+(const Fixed& other) const;
        Fixed operator-(const Fixed& other) const;
        Fixed operator*(const Fixed& other) const;
        Fixed operator/(const Fixed& other) const;
        // member functions
        static Fixed& min(Fixed& left, Fixed& right);
        static Fixed& max(Fixed& left, Fixed& right);
        static const Fixed& min(const Fixed& left, const Fixed& right);
        static const Fixed& max(const Fixed& left, const Fixed& right);
        float toFloat(void) const;
        int toInt(void) const;
        int getRawBits( void ) const;
        void setRawBits( int const raw );
};

std::ostream& operator<<(std::ostream& stream, const Fixed& other);

#endif