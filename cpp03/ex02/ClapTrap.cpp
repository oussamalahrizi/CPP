#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : HP(10), EP(10), AD(0)
{
    std::cout << "ClapTrap Default constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap Destructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string& name) :  HP(10), EP(10), AD(0)
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
        HP = other.HP;
        EP = other.EP;
        AD = other.AD;
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
    return (AD);
}

unsigned int ClapTrap::getHP() const
{
    return (HP);
}

unsigned int ClapTrap::getEP() const
{
    return (EP);
}

void ClapTrap::attack(const std::string& target)
{
    if (this->EP == 0 || this->HP == 0)
    {
        std::cout << "ClapTrap Cant attack " << target << ", no HP / EP left" << std::endl;
        return ;
    }
    EP--;
    std::cout << "ClapTrap " << Name
                << " attacks " << target
                << " , causing " << AD
                <<" points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if ((int)(HP - amount) <= 0)
        HP = 0;
    else
        HP -= amount;
    std::cout << "ClapTrap " << Name << " took "
                << amount << " of damage " << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (HP == 0)
    {
        std::cout << "ClapTrap Cant be repaired, No HP left" << std::endl;
        return;
    }
    else if (EP == 0)
    {
        std::cout << "ClapTrap Cant be repaired, Not enough EP" << std::endl;
        return;
    }
    HP += amount;
    EP--;
    std::cout << "ClapTrap " << Name << " healed by " << amount << std::endl;
}