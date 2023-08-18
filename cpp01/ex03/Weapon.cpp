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

const std::string &Weapon::getType() const
{
    return (this->type);
}

void    Weapon::setType(std::string type)
{
    this->type = type;
}