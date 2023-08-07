#include "Harl.hpp"

int get_level(std::string &level)
{
    int index = -1;

    if (level == "debug")
        index = 0;
    else if (level == "info")
        index = 1;
    else if (level == "warning")
        index = 2;
    else if (level == "error")
        index = 3;
    return (index);
}

void Harl::complain(std::string level)
{
    void (Harl::*function[4])() = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error,
    };

    int index = get_level(level);
    switch (index)
    {
        case 0:
        case 1:
        case 2:
        case 3:
            (this->*function[index])();
            break;
        default:
            std::cout << "Invalid level" << std::endl;
            break;
    }
}
