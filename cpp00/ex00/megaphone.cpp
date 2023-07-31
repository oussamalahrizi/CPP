#include <iostream>
#include <string>

#define DEFAULT "* LOUD AND UNBEARABLE FEEDBACK NOISE *"

std::string string_toupper(char *str)
{
	std::string res = str;
	unsigned long i = 0;
	while (i < res.length())
	{
		res[i] = toupper(res[i]);
		i++;
	}
	return (res);
}

int main(int ac, char **av)
{
	int i;

	if (ac == 1)
		std::cout << DEFAULT << std::endl;
	else
	{
		i = 1;
		while (av[i])
		{
			std::cout << string_toupper(av[i]);
			i++;
		}
		std::cout << std::endl;
	}
	return (0);
}