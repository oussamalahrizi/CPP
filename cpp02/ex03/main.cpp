#include <iostream>
#include "Fixed.hpp"

int main( void )
{
    Fixed a(10.5f);
    std::cout << a / 0.0f << std::endl;
    return 0;
}