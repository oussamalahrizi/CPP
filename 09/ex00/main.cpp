#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Invalid args " << std::endl;
        return (1);
    }
    BitcoinExchange e(av[1]);   
    return (0);
}