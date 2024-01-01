/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahrizi <olahrizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 06:21:51 by olahrizi          #+#    #+#             */
/*   Updated: 2023/12/21 06:12:47 by olahrizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

template <typename T>
void print(T& c)
{
	std::cout << c;
}

template <typename T>
void print_int(T& c)
{
	std::cout << c << " ";
}

template <typename T>
void toUpper(T& c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
}

template <typename T>
void increment(T& c)
{
	c++;
}

int main()
{
	std::string str("Hello world!");
	int tab[] = { 0, 1, 2, 3, 4 };
	

	std::cout << "string test :" << std::endl;
	std::cout << "before toUpper : " << std::endl;
	::iter(str.c_str(), str.length(), print);
	std::cout << std::endl;
	::iter(const_cast<char *>(str.c_str()), str.length(), toUpper);
	std::cout << "after toUpper : " << std::endl;
	::iter(str.c_str(), str.length(), print<const char>);
	std::cout << std::endl;
	std::cout << "----------------------" << std::endl;

	std::cout << "int tab test :" << std::endl;
	std::cout << "before increment : ";
	::iter(tab, 5, print_int);
	std::cout << std::endl;
	std::cout << "after increment : ";
	::iter(tab, 5, increment);
	::iter(tab, 5, print_int);
	std::cout << std::endl;
	return (0);
}