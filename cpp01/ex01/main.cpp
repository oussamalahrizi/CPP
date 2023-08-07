#include "Zombie.hpp"
#include <stdlib.h>
#include <string>
#include <sstream>

int main()
{
	Zombie *z = zombieHorde(5, "Exiled");
	if(z)
	{
		for (int i = 0; i < 5; i++)
			z[i].announce();
		delete[] z;
	}
	return 0;
}