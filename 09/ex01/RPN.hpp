#pragma once
#include <stack>
#include <iostream>
class RPN
{
    private:
        std::stack<int> data;
        int getTop();
    public:
        RPN();
        RPN(const RPN& other);
        RPN& operator=(const RPN& other);
        RPN(const std::string input);
        ~RPN();
};
