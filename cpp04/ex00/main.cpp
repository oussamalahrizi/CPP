#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"

int main()
{
    {
        const Animal *meta = new Animal();
        const Animal *j = new Dog();
        const Animal *i = new Cat();
        std::cout << j->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;
        i->makeSound(); // will output the cat sound!
        j->makeSound();
        meta->makeSound();

        delete meta;
        delete i;
        delete j;
    }
    std::cout << "--------------------" << std::endl;
    {
        const WrongAnimal *meta = new WrongAnimal();
        const WrongAnimal *i = new WrongCat();
        std::cout << i->getType() << " " << std::endl;
        i->makeSound(); // will output the WrongCat sound!
        meta->makeSound();
        delete meta;
        delete i;
    }

    return 0;
}