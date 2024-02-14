#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
    (void) other;
}
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
    (void) other;
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

int BitcoinExchange::CheckHead(std::string& line)
{
    if (line != "date | value")
    {
        std::cerr << "head of the data should be : \"date | value\"" << std::endl;
        return (0);
    }
    return (1);
}
int error(const std::string& msg)
{
    std::cerr << msg << std::endl;
    return (0);
}

int isNumeric(std::string& str)
{
    char c;
    int start = 0;
    if (str[0] == '-' || str[0] == '+')
        start++;
    int point = 0;
    for (size_t i = start; i < str.length(); i++)
    {
        c = str[i];
        if (!isdigit(c))
        {
            if (c == '.' && i != 0 && !point)
                point = 1;
            else
                return (0);
        }
    }
    return (1);
}

std::string checkDate(std::string& date)
{
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return "Incorrect date format => " + date;
    int year = atoi(date.substr(0, 4).c_str());
    int month = atoi(date.substr(5, 2).c_str());
    int day = atoi(date.substr(8, 2).c_str());
    if (year < 0 || month < 1 || month > 12
        || day < 1 || day > 31)
        return "Incorrect date format => " + date;
    return "valid";
}

int BitcoinExchange::handleDateValue(std::string& date, std::string& valueStr)
{
    std::string error;
    error = checkDate(date);
    if (date.empty() || valueStr.empty()
        || error != "valid" || !isNumeric(valueStr))
    
    {
        std::cerr << "Error : bad input => " + date + " | " + valueStr << std::endl;
        return (0);
    }
    float value = atof(valueStr.c_str());
    if (value < 0)
    {
        std::cerr << "Error : not a positive number." << std::endl;
        return (0);
    }
    if (value > 1000)
    {
        std::cerr << "Error : too large a number." << std::endl;
        return (0);
    }
    return (1);
}

void BitcoinExchange::handleLine(std::string& line)
{
    std::string pipe(" | ");
    if (line.empty())
    {
        std::cerr << "Error: empty line" << std::endl;
        return;
    }
    size_t index;
    if ((index = line.find(pipe)) == std::string::npos)
    {
        std::cerr << "Error: bad input => " << line << std::endl;
        return;
    }
    std::string date = line.substr(0, index);
    std::string value = line.substr(index + 3, line.length());
    if (!handleDateValue(date, value))
        return ;
    
}

void BitcoinExchange::DoStuff(const std::string& input)
{
    std::ifstream inputfile(input.c_str());
    std::ifstream db("data.csv");

    if (!inputfile.good() || !inputfile.is_open())
    {
        std::cerr << "Failed to open input file" << std::endl;
        return ;
    }
    if (!db.good() || !db.is_open())
    {
        std::cerr << "Failed to open the data base file" << std::endl;
        return ;
    }
    std::string line;
    std::getline(inputfile, line);
    if (!CheckHead(line))
        return ;
    while (std::getline(inputfile, line))
        handleLine(line);
    inputfile.close();
}