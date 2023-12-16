#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
    this->type = "WrongCat";
    std::cout << "WrongCat Default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
    std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
    if (this != &other)
        WrongAnimal::operator=(other);
    std::cout << "WrongCat copy operator called" << std::endl;
    return (*this);
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat desctructor called" << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << "Meow UwU" << std::endl;
}
