#pragma once

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <map>
#include <string>
#include <limits>

class BitcoinExchange
{
    private:
        std::ifstream data;
        std::ifstream input;
        std::string inputfile;
        static const std::string datafile;
        std::map<std::string, float> map;
    private:
        void DoStuff();
        int CheckHead(std::string& line);
        void handleLine(std::string &line);
        int handleDateValue(std::string& date, std::string& valueStr);
        BitcoinExchange();
        void readData();
        float searchValue(const std::string &date);
    public:
        BitcoinExchange(const std::string& file);
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);
        ~BitcoinExchange();
};
