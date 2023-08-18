#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : HitPoints(10), EnergyPoints(10), AttackDamage(0)
{
    std::cout << "ClapTrap Default constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap Destructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) :  HitPoints(10), EnergyPoints(10), AttackDamage(0)
{
    Name = name;
    std::cout << "ClapTrap Name constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    std::cout << "ClapTrap Copy assignement operator called" << std::endl;
    if(this != &other)
    {
        Name = other.Name;
        HitPoints = other.HitPoints;
        EnergyPoints = other.EnergyPoints;
        AttackDamage = other.AttackDamage;
    }
    return *this;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
    std::cout << "ClapTrap Copy constructor called" << std::endl;
    *this = other;
}

std::string ClapTrap::getName() const
{
    return (Name);
}

unsigned int ClapTrap::getAD() const
{
    return (AttackDamage);
}

unsigned int ClapTrap::getHP() const
{
    return (HitPoints);
}

unsigned int ClapTrap::getEP() const
{
    return (EnergyPoints);
}

void ClapTrap::attack(const std::string& target)
{
    if (this->EnergyPoints == 0 || this->HitPoints == 0)
    {
        std::cout << "ClapTrap Cant attack " << target << ", no HitPoints / EnergyPoints left" << std::endl;
        return ;
    }
    EnergyPoints--;
    std::cout << "ClapTrap " << Name
                << " attacks " << target
                << " , causing " << AttackDamage
                <<" points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if ((int)(HitPoints - amount) <= 0)
        HitPoints = 0;
    else
        HitPoints -= amount;
    std::cout << "ClapTrap " << Name << " took "
                << amount << " of damage " << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (HitPoints == 0)
    {
        std::cout << "ClapTrap Cant be repaired, No HitPoints left" << std::endl;
        return;
    }
    else if (EnergyPoints == 0)
    {
        std::cout << "ClapTrap Cant be repaired, Not enough EnergyPoints" << std::endl;
        return;
    }
    HitPoints += amount;
    EnergyPoints--;
    std::cout << "ClapTrap " << Name << " healed by " << amount << std::endl;
}
