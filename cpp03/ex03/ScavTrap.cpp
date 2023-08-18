#include "ScavTrap.hpp"


ScavTrap::ScavTrap() : ClapTrap()
{
    HitPoints = 100;
    EnergyPoints = 50;
    AttackDamage = 20;
    std::cout << "ScavTrap Default Constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    HitPoints = 100;
    EnergyPoints = 50;
    AttackDamage = 20;
    std::cout << "ScavTrap Name Constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    if (this != &other)
        ClapTrap::operator=(other);
    std::cout << "ScavTrap Copy operator called" << std::endl;
    return (*this);
}

ScavTrap::ScavTrap(const ScavTrap& other)
{
    std::cout << "ScavTrap Copy Constructor called" << std::endl;
    *this = other;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap Destructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (this->EnergyPoints == 0 || this->HitPoints == 0)
    {
        std::cout << "ScavTrap Cant attack " << target << ", no HitPoints / EnergyPoints left" << std::endl;
        return ;
    }
    EnergyPoints--;
    std::cout << "ScavTrap " << Name
                << " attacks " << target
                << " , causing " << AttackDamage
                <<" points of damage!" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
}