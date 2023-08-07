#include "Harl.hpp"


int main(int ac, char **av)
{
    if (ac != 2)
        return (1);
    Harl harl;

    std::string str(av[1]);
    for (size_t i = 0; i < str.length(); i++)
    {
        str[i] = std::tolower(str[i]);
    }
    
    harl.complain(str);
    return (0);
}