/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahrizi <olahrizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 06:40:41 by olahrizi          #+#    #+#             */
/*   Updated: 2023/12/22 02:49:42 by olahrizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <exception>
#include <stdexcept>

template <typename T>
bool easyfind(T &container, int value)
{
	typename T::iterator begin = container.begin();
	typename T::iterator end = container.end();
	
	for(typename T::iterator it = begin; it != end;  it++)
		if (*it == value)
			return(true);
	throw std::runtime_error("value not found");
	return(false);
}
