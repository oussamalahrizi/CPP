#include "FragTrap.hpp"


FragTrap::FragTrap() : ClapTrap()
{
    HP = 100;
    EP = 100;
    AD = 30;
    std::cout << "FragTrap Default Constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    HP = 100;
    EP = 100;
    AD = 30;
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
    if (this->EP == 0 || this->HP == 0)
    {
        std::cout << "FragTrap Cant attack " << target << ", no HP / EP left" << std::endl;
        return ;
    }
    EP--;
    std::cout << "FragTrap " << Name
                << " attacks " << target
                << " , causing " << AD
                <<" points of damage!" << std::endl;
}

void FragTrap::highFivesGuys()
{
    std::cout << "FragTrap : High Five Guys!" << std::endl;
}