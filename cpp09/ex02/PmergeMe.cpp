#include "PmergeMe.hpp"
#include <_ctype.h>
#include <cctype>
#include <cstddef>
#include <cstdlib>
#include <ctime>
#include <iterator>
#include <stdexcept>
#include <vector>
#include <algorithm>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other)
{
	*this = other;
}

PmergeMe::~PmergeMe() {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	(void) other;
	return (*this);
}

int isNumber(char *input)
{
	int i = 0;
	while (input[i] && isspace(input[i]))
		i++;
	if (input[i] == '-' || input[i] =='+')
		i++;
	while (input[i] && isdigit(input[i]))
		i++;
	if (!input[i])
		return (1);
	return (0);
}

PmergeMe::PmergeMe(int ac, char **av)
{
	int i = 1;
	while (i < ac)
	{
		if (isNumber(av[i]))
		{
			this->vec.push_back(atoi(av[i]));
			this->deq.push_back(atoi(av[i]));
		}
		else
			throw std::runtime_error("Error : not a number");
		i++;
	}
	if (!this->CheckDuplicates(this->vec)
		|| !this->CheckDuplicates(this->deq))
		throw std::runtime_error("Error : Duplicates.");
	this->doStuff();
}
template <typename T>
void PmergeMe::display(T& vec) const 
{
	typename T::const_iterator it = vec.begin();
	while (it != vec.end())
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
}
template <typename T>
int PmergeMe::CheckDuplicates(T &vec)
{
	typename T::const_iterator it1 = vec.begin();
	typename T::const_iterator it2;
	while (it1 != vec.end())
	{
		it2 = it1 + 1;
		while (it2 != vec.end())
		{
			if (*it2 == *it1)
				return (0);
			it2++;
		}
		it1++;
	}
	return (1);
}


void PmergeMe::doStuff()
{
	std::cout << "Before : "; 
	this->display(this->vec);
	std::cout << "After : ";
	clock_t vec_time = this->sort(this->vec);
	clock_t deq_time = this->sort(this->deq);
	this->display(this->vec);
	std::cout << "Time to process a range of " << this->vec.size()
	<< " elements with std::vector : " << static_cast<double>(vec_time) << " us" << std::endl;
	std::cout << "Time to process a range of " << this->deq.size()
	<< " elements with std::deque : " << deq_time << " us" << std::endl;
}

template<typename T>
clock_t PmergeMe::sort(T& vec)
{
	clock_t start, end;
	T chain;
	start = clock();
	if (vec.size() > 1)
	{
		for (size_t i = 0; i < vec.size() - 1; i++)
		{
			if (vec[i] < vec[i + 1])
			{
				chain.push_back(vec[i]);
				vec.erase(vec.begin() + i);
			}
			else
			{
				chain.push_back(vec[i + 1]);
				vec.erase(vec.begin() + i + 1);
			}
		}
		this->sort(vec);
	}
	while (chain.size() > 0)
	{
		int index = this->BinaryInsert(vec, 0, vec.size() - 1, chain[0]);
		vec.insert(vec.begin() + index, chain[0]);
		chain.erase(chain.begin());
	}
	end = clock();
	return (end - start);
}
template <typename T>
int PmergeMe::BinaryInsert(T& vec, int left, int right, int value)
{
	if (right >= left)
	{
		int mid = left + (right - left) / 2;
		if (vec[mid] > value)
			return (this->BinaryInsert(vec, left, mid - 1, value));
		return (this->BinaryInsert(vec, mid + 1, right, value));
	}
	return (left);
}
