

#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main()
{
	{
		// IMateriaSource* src = new MateriaSource();
		// AMateria *ice = new Ice();
		// AMateria *cure = new Cure();
		// src->learnMateria(ice);
		// src->learnMateria(cure);
		// ICharacter* me = new Character("me");
		// AMateria* tmp;
		// tmp = src->createMateria("ice");
		// me->equip(tmp);
		// delete tmp;
		// tmp = src->createMateria("cure");
		// me->equip(tmp);
		// ICharacter* bob = new Character("bob");
		// me->use(0, *bob);
		// me->use(1, *bob);
		// delete bob;
		// delete me;
		// delete src;
		// delete ice;
		// delete cure;
	}
	{
		MateriaSource *src = new MateriaSource();
		AMateria *ice = new Ice();
		AMateria *cure = new Cure();
		src->learnMateria(ice);
		src->learnMateria(cure);
		IMateriaSource *clone = new MateriaSource(*src);
		AMateria *tmp = clone->createMateria("nothing");
		delete tmp;
		tmp = clone->createMateria("cure");
		ICharacter *me = new Character("me");
		ICharacter *bob = new Character("bob");
		me->equip(tmp);
		me->use(0, *bob);
		delete tmp;
		delete me;
		delete bob;
		delete src;
		delete clone;
		delete cure;
		delete ice;
	}
	return 0;
}