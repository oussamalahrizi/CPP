#pragma once

#include <deque>
#include <iostream>
#include <vector>

class PmergeMe
{
	private:
		std::vector<int> vec;
		std::deque<int>deq;
		template <typename T>
		void display(T& vec) const ;
		template <typename T>
		int CheckDuplicates(T& vec);
		void doStuff();
		template<typename T>
		clock_t sort(T& vec);
		template <typename T>
		int BinaryInsert(T& vec, int left, int right,
				   int value);
	public:
		PmergeMe();
		PmergeMe(int ac, char **av);
		PmergeMe(const PmergeMe& other);
		~PmergeMe();
		PmergeMe& operator=(const PmergeMe& other);
};
