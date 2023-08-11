#include "ClapTrap.hpp"

int main()
{
    std::string name("Player");
    ClapTrap a(name);

    std::cout << "Player status : " << std::endl;
    std::cout << "AD " << a.getAD() << std::endl;
    std::cout << "EP " <<  a.getEP() << std::endl;
    std::cout << "HP " << a.getHP() << std::endl;

    a.attack("other player");
    a.takeDamage(20);
    a.beRepaired(5);

    std::cout << "Player status : " << std::endl;
    std::cout << "AD " << a.getAD() << std::endl;
    std::cout << "EP " <<  a.getEP() << std::endl;
    std::cout << "HP " << a.getHP() << std::endl;
    return (0);
}