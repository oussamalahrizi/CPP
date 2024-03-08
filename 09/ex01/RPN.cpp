#include "RPN.hpp"


RPN::RPN() {}

RPN::RPN(const RPN& other)
{
    *this = other;
}

RPN& RPN::operator=(const RPN& other)
{
    if (this != &other)
        this->data = other.data;
    return (*this);
}

int RPN::getTop()
{
    int number = this->data.top();
    this->data.pop();
    return number;
}


RPN::RPN(const std::string input)
{
    for (size_t i = 0; i < input.length(); i++)
    {
        if (isspace(input[i]))
            continue;
        if (isdigit(input[i]))
            this->data.push(input[i] - 48);
        else if (input[i] == '-')
        {
            if (this->data.size() < 2)
                throw std::runtime_error("Error");
            int n1 = this->getTop();
            int n2 = this->getTop();
            this->data.push(n2 - n1);
        }
        else if (input[i] == '+')
        {
            if (this->data.size() < 2)
                throw std::runtime_error("Error");

            int n1 = this->getTop();
            int n2 = this->getTop();
            this->data.push(n2 + n1);
        }
        else if (input[i] == '*')
        {
            if (this->data.size() < 2)
                throw std::runtime_error("Error");
            int n1 = this->getTop();
            int n2 = this->getTop();
            this->data.push(n2 * n1);
        }
        else if (input[i] == '/')
        {
            if (this->data.size() < 2)
                throw std::runtime_error("Error");

            int n1 = this->getTop();
            int n2 = this->getTop();
            if (n1 == 0)
            {
                std::cerr << "cant divide by 0\n";
                throw std::runtime_error("Error");
            }
            this->data.push(n2 / n1);
        }
        else
            throw std::runtime_error("Error");
    }
    if (this->data.size() == 1)
        std::cout << this->data.top() << std::endl;
    else 
        throw std::runtime_error("Error");
    
}

RPN::~RPN() {}