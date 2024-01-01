
#pragma once

#include "Array.hpp"
#include <exception>


template <typename T>
Array<T>::Array()
{
	this->m_arr = NULL;
	this->m_size = 0;
}

template <typename T>
Array<T>::~Array()
{
	delete[] this->m_arr;
}

template <typename T>
Array<T>::Array(size_t n)
{
	this->m_arr = new T[n]();
	this->m_size = n;
}

template <typename T>
Array<T>::Array(const Array& other) : m_arr(NULL)
{
	*this = other;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other)
{
	if (this != &other)
	{
		if (this->m_arr)
			delete[] this->m_arr;
		this->m_size = other.m_size;
		this->m_arr = new T[this->m_size]();
		for (size_t i = 0; i < this->m_size; i++)
			this->m_arr[i] = other.m_arr[i];
	}
	return (*this);
}

template <typename T>
T& Array<T>::operator[](size_t index) const
{
	if (index >= this->m_size)
		throw std::runtime_error("Index out of bounds");
	return (this->m_arr[index]);
}

template <typename T>
size_t Array<T>::size() const
{
	return (this->m_size);
}