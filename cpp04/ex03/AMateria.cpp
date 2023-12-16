#include "AMateria.hpp"

AMateria::AMateria() {}

AMateria::AMateria(std::string const &type) : type(type) {}

AMateria& AMateria::operator=(const AMateria& other)
{
    (void) other;
    return (*this);
}

AMateria::AMateria(const AMateria& other)
{
    *this = other;
}

AMateria::~AMateria() {}

std::string const & AMateria::getType() const
{
    return (this->type);
}

void AMateria::use(ICharacter& target)
{
    (void) target;
    std::cout << this->type << " doesn't do anything" << std::endl;
}