#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : free_index(0)
{
    for (size_t i = 0; i < 4; i++)
        this->slots[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
    int i;
    for (i = 0; i < other.free_index; i++)
        this->slots[i] = other.slots[i]->clone();
    while (i < 4)
    {
        this->slots[i] = NULL;
        i++;
    }
    this->free_index = other.free_index;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
        delete this->slots[i];
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
    if (this != &other)
    {
        int i;
        for (i = 0; i < this->free_index; i++)
            if (this->slots[i] != NULL)
                delete this->slots[i];
        for (i = 0; i < other.free_index; i++)
            this->slots[i] = other.slots[i]->clone();
        while (i < 4)
        {
            this->slots[i] = NULL;
            i++;
        }
        this->free_index = other.free_index;
    }
    return (*this);
}

void MateriaSource::learnMateria(AMateria * learn)
{
    if (!learn)
        return;
    if (this->free_index > 3)
    {
        std::cout << "not enough space to learn a new Materia" << std::endl;
        return;
    }
    this->slots[this->free_index++] = learn->clone();
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < this->free_index; i++)
    {
        if (this->slots[i]->getType() == type)
            return (this->slots[i]->clone());
    }
    std::cout << "Unknown type" << std::endl;   
    return (NULL);
}
