#include <iostream>

#include "MutantStack.hpp"

#include <list>
int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	std::cout << "---- printing from mutantstack ----" << std::endl;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::stack<int> s(mstack);
	std::list<int> l(mstack.begin(), mstack.end());
	std::list<int>::iterator lit = l.begin();
	std::cout << "---- printing from list ----" << std::endl;
	while (lit != l.end())
	{
		std::cout << *lit << std::endl;
		lit++;
	}
	return 0;
}
