/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahrizi <olahrizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 06:17:50 by olahrizi          #+#    #+#             */
/*   Updated: 2023/12/21 02:11:59 by olahrizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template <typename T>
void iter(T *arr, size_t len, void (*f)(T&))
{
	for (size_t i = 0; i < len; i++)
		f(arr[i]);
}