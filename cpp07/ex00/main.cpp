/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahrizi <olahrizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 06:06:32 by olahrizi          #+#    #+#             */
/*   Updated: 2023/12/19 06:16:27 by olahrizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

#include <ostream>


std::ostream& operator<<(std::ostream& os, const Data& d)
{
	os << d.s1 << ", " << d.n << ", " << d.s2;
	return os;
}

bool operator<(Data& d, Data& d2)
{
	if (d.n < d2.n)
		return true;
	return false;
}

bool operator>(Data& d, Data& d2)
{
	if (d.n > d2.n)
		return true;
	return false;
}

int main( void )
{
	#if 1
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	#else
		Data a = {"chaine1", 42, "chaine2"};
		Data b = {"chaine3", 21, "chaine4"};
		// ::swap(a, b);
		// std::cout << "a = " << a.s1 << ", " << a.n << ", " << a.s2 << std::endl;
		// std::cout << "b = " << b.s1 << ", " << b.n << ", " << b.s2 << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	#endif
	return 0;
}