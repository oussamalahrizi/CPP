#include "Zombie.hpp"
#include <stdlib.h>
#include <string>
#include <sstream>

int main()
{
	Zombie *z1 = newZombie("Exiled");
	z1->announce();
	randomChump("random");
	delete z1;
	return 0;
}