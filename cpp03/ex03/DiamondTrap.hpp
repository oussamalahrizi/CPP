#pragma once

#include "ScavTrap.hpp"
#include "FragTrap.hpp"


class Base
{
    protected:
        std::string name;
    public:
        Base()
        {
            std::cout << "BASE DEFAULT CONSTRUCTOR CALLED\n" << std::endl;
        }
        Base(const std::string& name) : name(name)
        {
            std::cout << "BASE PARAM CONSTRUCTOR CALLED\n" << std::endl;
        }
        ~Base() {};

        void foo()
        {
            std::cout << "foo base class" << std::endl;
        }
};

class A : public Base
{
    public : 
        A() : Base()
        {
            std::cout << "A DEFAULT CONSTRUCTOR CALLED\n" << std::endl;
        }
        A(const std::string& name) : Base(name)
        {
            std::cout << "A PARAM CONSTRUCTOR CALLED\n" << std::endl;
        }
        ~A() {};

        void foo()
        {
            std::cout << "foo A class" << std::endl;
        }
};

class B : public Base
{
    public : 
        B() : Base()
        {
            std::cout << "B DEFAULT CONSTRUCTOR CALLED\n" << std::endl;
        }
        B(const std::string& name) : Base(name)
        {
            std::cout << "B PARAM CONSTRUCTOR CALLED\n" << std::endl;
        }
        ~B() {};

        void foo()
        {
            std::cout << "foo B class" << std::endl;
        }
};



class Derived : public A, public B
{
    public:
        Derived()
        {
            std::cout << "DERIVED DEFAULT CONSTRUCTOR CALLED" << std::endl;
        }
        ~Derived() {}
};