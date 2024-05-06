#include "Span.hpp"


Span::Span() : size(0) {}

Span::Span(unsigned int n) : size(n) {}

Span::Span(const Span& other)
{
	*this = other;
}

Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
		this->numbers.clear();
		this->size = other.size;
		this->addNumber(other.numbers.begin(), other.numbers.end());
	}
	return *this;
}

Span::~Span()
{
	this->numbers.clear();
}

void Span::addNumber(int value)
{
	if (this->numbers.size() >= this->size)
		throw std::runtime_error("exception : can't add value, Span full");
	this->numbers.push_back(value);
}

int Span::shortestSpan() const 
{
	if (this->size < 2)
		throw std::runtime_error("size too small");
	std::list<int> temp(this->numbers.begin(), this->numbers.end());
	temp.sort();
	std::list<int>::iterator it = temp.begin();
	std::list<int>::iterator next;
	int min = std::numeric_limits<int>::max();
	while (it != temp.end())
	{
		next = std::next(it);
		if (next != temp.end())
			min = std::min(min, *next - *it);
		it++;
	}
	return (min);
}

int Span::longestSpan() const
{
	if (this->size < 2)
		throw std::runtime_error("size too small");
	std::list<int> temp(this->numbers.begin(), this->numbers.end());
	temp.sort();
	int max = temp.back() - temp.front();
	return (max);
}
