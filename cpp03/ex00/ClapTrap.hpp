#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
    private:
        std::string Name;
        unsigned int HP;
        unsigned int EP;
        unsigned int AD;

    public:
        //constructors
        ClapTrap();
        ClapTrap(std::string& name);
        ClapTrap(ClapTrap& other);
        ~ClapTrap();
    
        //copy operator
        ClapTrap& operator=(const ClapTrap& other);
    
        // member functions
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        std::string getName() const;
        unsigned int getHP() const;
        unsigned int getAD() const;
        unsigned int getEP() const;

};



#endif