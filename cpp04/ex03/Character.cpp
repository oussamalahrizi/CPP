#include "Character.hpp"

Character::Character(const std::string& name) : name(name), free_index(0)
{
	for (size_t i = 0; i < 4; i++)
	{
		this->slots[i] = NULL;
		this->save[i] = NULL;
	}
}

Character::Character(const Character& other)
{
	*this = other;
}

Character& Character::operator=(const Character& other)
{
	if (this != &other)
	{
		int i;
		for (i = 0; i < free_index; i++)
		{
			if (this->save[i] != NULL)
				delete this->save[i];
		}
		for (i = 0; i < other.free_index; i++)
		{
			this->slots[i] = other.slots[i]->clone();
			this->save[i] = this->slots[i];
		}
		while (i < 4)
		{
			this->save[i] = NULL;
			this->slots[i] = NULL;
			i++;
		}
		this->free_index = other.free_index;
		this->name = other.name;
	}
	return (*this);
}

Character::~Character()
{
	for(int i = 0; i < 4; i++)
		delete this->save[i];
}

std::string const & Character::getName() const
{
	return (this->name);
}

void Character::equip(AMateria* m)
{
	if (!m)
		return;
	if (free_index > 3)
	{
		std::cout << "no free space to add the material" << std::endl;
		return;
	}
	this->slots[free_index] = m->clone();
	delete this->save[free_index];
	this->save[free_index] = this->slots[free_index];
	free_index++;
	std::cout << "Material added at index : " << free_index - 1 << std::endl;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= free_index)
	{
		std::cout << "Can't use Material : index out of range" << std::endl;
		return;
	}
	this->slots[idx]->use(target);
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << "Can't unequip Material : index out of range" << std::endl;
		return;
	}
	for (int i = idx; i < 3; i++)
		this->slots[i] = this->slots[i + 1];
	this->slots[3] = NULL;
	free_index--;
	std::cout << "Material removed from index " << idx << std::endl;
}

void print_slots(Character *player)
{
	for (int i = 0; i < player->free_index; i++)
		std::cout << player->slots[i]->getType() << std::endl;
}
