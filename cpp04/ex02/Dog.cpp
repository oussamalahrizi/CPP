#include "Dog.hpp"

Dog::Dog() : Animal()
{
    this->brain = new Brain();
    this->type = "Dog";
    std::cout << "Dog Default constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other)
{
    std::cout << "Dog Copy constructor called" << std::endl;
    *this = other;
}

Dog& Dog::operator=(const Dog& other)
{
    if (this != &other)
    {
        Animal::operator=(other);
        delete this->brain;
        this->brain = new Brain(*(other.brain));
    }
    std::cout << "Dog Copy operator called" << std::endl;
    return (*this);
}

Dog::~Dog()
{
    delete brain;
    std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound()
{
    std::cout << "Woof Woof" << std::endl;
}

std::string Dog::getType()
{
    return (this->type);
}
