#include "easyfind.hpp"
#include <exception>
#include <iostream>
#include <vector>


int main(int , char **)
{
	std::vector<int> vec;
	for (size_t i = 0; i < 2; i++)
		vec.push_back(i + 1);
	try
	{
		std::cout << easyfind(vec, 1) << std::endl;
		std::cout << "found 1" << std::endl;
		std::cout << easyfind(vec, 10);
		std::cout << "found 1" << std::endl;
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
