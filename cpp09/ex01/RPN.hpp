#pragma once
#include <stack>
#include <iostream>
#include <stdexcept>
class RPN
{
    private:
        std::stack<double> data;
        int getTop();
		void PerformOperation(char c);
    public:
        RPN();
        RPN(const RPN& other);
        RPN& operator=(const RPN& other);
        RPN(const std::string input);
        ~RPN();
};
