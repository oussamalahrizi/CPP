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
        Fixed();
        Fixed(const Fixed &other);
        Fixed(const int value);
        Fixed(const float value);
        ~Fixed();

        Fixed& operator=(const Fixed& other);

        float toFloat(void) const;
        int toInt(void) const;
        int getRawBits( void ) const;
        void setRawBits( int const raw );
};

std::ostream& operator<<(std::ostream& stream, const Fixed& other);

#endif