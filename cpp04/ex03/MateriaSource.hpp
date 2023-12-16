

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
    private:
        AMateria *slots[4];
        int free_index;
    public:
        MateriaSource();
        MateriaSource(const MateriaSource& other);
        ~MateriaSource();

        MateriaSource& operator=(const MateriaSource& other);
        void learnMateria(AMateria* learn);
        AMateria* createMateria(std::string const & type);

};