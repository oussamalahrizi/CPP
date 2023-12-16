#pragma once

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Character : public ICharacter
{
    private:
        std::string name;
        int free_index;
        AMateria *slots[4];
        AMateria *save[4];
    public:
        Character(const std::string& name);
        Character(const Character& other);
        ~Character();

        Character& operator=(const Character& other);

        std::string const & getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);

        friend void print_slots(Character *player);
};
