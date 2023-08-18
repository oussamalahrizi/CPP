#include "ScavTrap.hpp"


ScavTrap::ScavTrap() : ClapTrap()
{
    HP = 100;
    EP = 50;
    AD = 20;
    std::cout << "ScavTrap Default Constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    HP = 100;
    EP = 50;
    AD = 20;
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
    if (this->EP == 0 || this->HP == 0)
    {
        std::cout << "ScavTrap Cant attack " << target << ", no HP / EP left" << std::endl;
        return ;
    }
    EP--;
    std::cout << "ScavTrap " << Name
                << " attacks " << target
                << " , causing " << AD
                <<" points of damage!" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
}