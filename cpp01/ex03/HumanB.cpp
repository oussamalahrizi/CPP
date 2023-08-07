#include "HumanB.hpp"

HumanB::HumanB() {}

HumanB::HumanB(std::string name)
{
    this->name = name;
    this->weapon = NULL;
}

void HumanB::setWeapon(Weapon &weapon)
{
    this->weapon = &weapon;
}

HumanB::~HumanB()
{
    std::cout << "Human B with name " << this->name << " destroyed" << std::endl;
}

void HumanB::attack()
{
    if (this->weapon == NULL)
    {
        std::cout << this->name << " does not have a weapon." << std::endl;
        return;
    }
    std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}