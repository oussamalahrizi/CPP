#include "Animal.hpp"

Animal::Animal() : type("No Type")
{
    std::cout << "Animal Default constructor called" << std::endl;
}

Animal::Animal(const Animal& other)
{
    std::cout << "Animal Copy Constructor called" << std::endl;
    *this = other;
}

Animal& Animal::operator=(const Animal& other)
{
    if (this != &other)
        this->type = other.type;
    std::cout << "Animal Copy operator called" << std::endl;
    return (*this);
}

Animal::~Animal()
{
    std::cout << "Animal Destructor called" << std::endl;
}

void Animal::makeSound() const
{
    std::cout << "Animal has no sound" << std::endl;
}

std::string Animal::getType() const
{
    return (this->type);
}