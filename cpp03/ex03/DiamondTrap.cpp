#include "DiamondTrap.hpp"


DiamondTrap::DiamondTrap()
{
    this->HitPoints = FragTrap::HitPoints;
    this->EnergyPoints = ScavTrap::EnergyPoints;
    this->AttackDamage = FragTrap::AttackDamage;
    std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string name) : ClapTrap(name + "_clap_name")
{
    this->Name = name;
    this->HitPoints = FragTrap::HitPoints;
    this->EnergyPoints = ScavTrap::EnergyPoints;
    this->AttackDamage = FragTrap::AttackDamage;
    std::cout << "DiamondTrap name constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap destructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) 
{
    std::cout << "DiamondTrap copy assignement called" << std::endl;
    if (this != &other)
    {
        this->Name = other.Name;
        ClapTrap::operator=(other);
    }
    return (*this);
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
{
    std::cout << "DiamondTrap copy constructor called" << std::endl;
    *this = other;
}

void DiamondTrap::attack(const std::string& target)
{
    std::cout << "DiamonTrap attacks : ";
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
    std::cout << "DiamonTrap name : " << this->Name << std::endl;
    std::cout << "ClapTrap name : " << ClapTrap::Name << std::endl;
}