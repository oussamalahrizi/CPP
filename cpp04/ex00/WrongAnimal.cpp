#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("No Type")
{
    std::cout << "WrongAnimal Default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
    std::cout << "WrongAnimal Copy Constructor called" << std::endl;
    *this = other;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
    if (this != &other)
        this->type = other.type;
    std::cout << "WrongAnimal Copy operator called" << std::endl;
    return (*this);
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal Destructor called" << std::endl;
}

void WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal has no sound" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return (this->type);
}