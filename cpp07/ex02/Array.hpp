/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahrizi <olahrizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 05:24:15 by olahrizi          #+#    #+#             */
/*   Updated: 2023/12/21 05:59:01 by olahrizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>


template <typename T>
class Array
{
	private:
		T *m_arr;
		size_t m_size;
	public:
		Array();
		Array(size_t n);
		Array(const Array& other);
		Array& operator=(const Array& other);
		T& operator[](size_t index) const;
		~Array();
	
		size_t size() const;
};

#include "Array.tpp"