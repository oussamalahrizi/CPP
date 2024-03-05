#include "BitcoinExchange.hpp"

const std::string BitcoinExchange::datafile = "data.csv";

BitcoinExchange::BitcoinExchange(const std::string& file)
{
    this->data.open(this->datafile.c_str());
    if (!this->data.is_open() || !this->data.good())
    {
        std::cerr   << "failed to open the data.csv file " <<
                    "please make sure it exists in ./" <<
                    std::endl;
        exit(1); 
    }
    this->inputfile = file;
    this->input.open(inputfile.c_str());
    if (!this->input.is_open() || !this->input.good())
    {
        std::cerr   << "failed to open the input file " << std::endl;
        exit(1); 
    }
    DoStuff();
}

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
    *this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
    if (this != &other)
    {
        this->input.close();
        this->data.close();
        this->inputfile = other.inputfile;
        this->input.open(inputfile.c_str());
        this->data.open(this->datafile.c_str());
        this->map = other.map;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange()
{
    this->data.close();
    this->input.close();
}

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
    // std::cout << "return is : " << searchValue(date) << std::endl;
    std::cout << date << " => ";
    std::cout << value << " = ";
    std::cout << searchValue(date) * atof(value.c_str()) << std::endl;
}

void BitcoinExchange::DoStuff()
{
    readData();
    std::string line;
    std::getline(this->input, line);
    if (!CheckHead(line))
        return ;
    while (std::getline(input, line))
        handleLine(line);
}

void BitcoinExchange::readData()
{
    std::string line;
    std::string key, value;

    std::getline(this->data, line);
    while (std::getline(this->data, line))
    {
        key = line.substr(0, 10);
        value = line.substr(11, line.length());
        map[key] = std::atof(value.c_str());
    }
}

float BitcoinExchange::searchValue(const std::string& date)
{
    // calcuations done assuming the map container is date sorted
    std::map<std::string , float>::iterator it = this->map.lower_bound(date);
    if (it == this->map.begin() && date < it->first) // date given is less than any date
        return (it->second);
    else if (it == this->map.end()) // date given greater than anydate
        it--;
    else if (it->first != date) // date not found return the closest lower date
        it--;
    // otherwise the date is found
    return (it->second);
}

