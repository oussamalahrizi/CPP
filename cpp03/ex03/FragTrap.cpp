#include "FragTrap.hpp"


FragTrap::FragTrap() : ClapTrap()
{
    HitPoints = 100;
    EnergyPoints = 100;
    AttackDamage = 30;
    std::cout << "FragTrap Default Constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    HitPoints = 100;
    EnergyPoints = 100;
    AttackDamage = 30;
    std::cout << "FragTrap Name Constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
    if (this != &other)
        ClapTrap::operator=(other);
    std::cout << "FragTrap Copy operator called" << std::endl;
    return (*this);
}

FragTrap::FragTrap(const FragTrap& other)
{
    std::cout << "FragTrap Copy Constructor called" << std::endl;
    *this = other;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap Destructor called" << std::endl;
}

void FragTrap::attack(const std::string& target)
{
    if (this->EnergyPoints == 0 || this->HitPoints == 0)
    {
        std::cout << "FragTrap Cant attack " << target << ", no HitPoints / EnergyPoints left" << std::endl;
        return ;
    }
    EnergyPoints--;
    std::cout << "FragTrap " << Name
                << " attacks " << target
                << " , causing " << AttackDamage
                <<" points of damage!" << std::endl;
}

void FragTrap::highFivesGuys()
{
    std::cout << "FragTrap : High Five Guys!" << std::endl;
}