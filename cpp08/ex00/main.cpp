#include "easyfind.hpp"
#include <iostream>
#include <vector>

int main(int , char **)
{
	std::vector<int> vec;


	for (size_t i = 0; i < 20; i++)
		vec.push_back(i + 1);
	bool found = false;
	try
	{
		found = easyfind(vec, 0);
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << found << std::endl;
	return (0);
	
}