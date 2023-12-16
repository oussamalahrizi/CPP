#include "Cat.hpp"

Cat::Cat() : Animal()
{
    this->type = "Cat";
    std::cout << "Cat Default constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other)
{
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
    if (this != &other)
        Animal::operator=(other);
    std::cout << "Cat copy operator called" << std::endl;
    return (*this);
}

Cat::~Cat()
{
    std::cout << "Cat desctructor called" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Meow UwU" << std::endl;
}

