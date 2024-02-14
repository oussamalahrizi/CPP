#pragma once

#include <iostream>
#include <fstream>
#include <cstdlib>

class BitcoinExchange
{
    private:
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange();
        BitcoinExchange& operator=(const BitcoinExchange& other);
        ~BitcoinExchange();
    public:
        static void DoStuff(const std::string& input);
        static int CheckHead(std::string& line);
        static void handleLine(std::string &line);
        static int handleDateValue(std::string& date, std::string& valueStr);
};
