#include "Weapon.hpp"

Weapon::Weapon() {}

Weapon::Weapon(std::string type)
{
    this->type = type;
}

Weapon::~Weapon()
{
    std::cout << "weapon with type " << this->type << " destroyed" << std::endl;
}

std::string &Weapon::getType()
{
    return (this->type);
}

void    Weapon::setType(std::string type)
{
    this->type = type;
}