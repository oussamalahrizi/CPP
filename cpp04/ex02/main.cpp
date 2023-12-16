#include "Cat.hpp"
#include "Dog.hpp"
# include <string>

int main()
{
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    delete j; //should not create a leak
    delete i;
    const Cat *a =  new Cat();
    Cat *b = new Cat();
    *b = *a;

    b->makeSound();
    std::cout << b->getType() << std::endl;
    delete b;
    delete a;
    return 0;
}