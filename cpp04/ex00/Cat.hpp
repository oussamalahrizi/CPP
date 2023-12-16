#pragma once

# include "Animal.hpp"
# include <cstdlib>

class Cat : public Animal
{
    public:
        Cat();
        Cat(const Cat& other);
        ~Cat();

        Cat& operator=(const Cat& other);

        void makeSound() const;
};
