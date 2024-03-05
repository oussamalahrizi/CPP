#pragma once
#include <stack>
class RPN
{
    private:
        std::stack<int> data;
    public:
        RPN();
        RPN(const char *av);
        ~RPN();
};
