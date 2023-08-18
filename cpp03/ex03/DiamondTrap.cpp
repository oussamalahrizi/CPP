#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() {}

DiamondTrap::DiamondTrap(std::string name) : name(name) , ClapTrap(name + "_clap_name")
{
    
}