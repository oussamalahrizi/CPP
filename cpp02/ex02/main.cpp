#include <iostream>
#include "Fixed.hpp"

int main( void )
{
    Fixed a ( Fixed(2.0f) * Fixed(0.5f));
    
    std::cout << "a address : " << &a << std::endl;

    return 0;
}