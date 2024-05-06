#include "Span.hpp"

#include <exception>
#include <iostream>
#include <vector>

int main(void)
{
	{
		Span test(5);

		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	{
		std::vector<int> vec;
		Span span(100000);
		for (int i = 0; i < 100000; i++)
			vec.push_back(i + 1);
		try
		{
			span.addNumber(vec.begin(), vec.end());
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	return (0);
}
