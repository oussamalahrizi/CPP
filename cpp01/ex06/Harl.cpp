#include "Harl.hpp"


void Harl::debug()
{
    std::cout << "[ DEGUG ]" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger."
                << std::endl << "really do!"
                << std::endl;
}

void Harl::info()
{
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money."
                << std::endl << "didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"
                << std::endl;
}

void Harl::warning()
{
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free."
                << std::endl << "been coming for years whereas you started working here since last month."
                << std::endl;

}

void Harl::error()
{
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

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
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
            break;
    }
}
