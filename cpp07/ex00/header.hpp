/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahrizi <olahrizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 06:06:53 by olahrizi          #+#    #+#             */
/*   Updated: 2023/12/19 06:16:00 by olahrizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template <typename T>
void swap(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}


template <typename T>
T min(T& a, T& b)
{
    return (a < b) ? a : b;
}


template <typename T>
T	 max(T& a, T& b)
{
    return (a > b) ? a : b;
}

struct Data { std::string s1; int n; std::string s2; };

bool operator<(Data& d, Data& d2);
bool operator>(Data& d, Data& d2);