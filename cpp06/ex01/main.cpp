/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahrizi <olahrizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 04:18:10 by olahrizi          #+#    #+#             */
/*   Updated: 2023/12/19 05:25:34 by olahrizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

void print_data(Data *data)
{
	std::cout << "name: " << data->name << std::endl;
	std::cout << "age: " << data->age << std::endl;
	std::cout << "salary: " << data->salary << std::endl;
}

int main()
{
	/*
	// notice that the address that ptr is pointing to is the same as the value of p but as decimal
	int *ptr = new int(42);
	uintptr_t p = reinterpret_cast<uintptr_t>(ptr);
	std::cout << "p :" << p << std::endl;
	std::cout << "ptr :" << ptr << std::endl;
	
	*/
	Data *data = new Data;
	data->name = "Oussama";
	data->age = 24;
	data->salary = 1000.0f;
	uintptr_t p = Serializer::serialize(data);
	std::cout << "p :" << p << std::endl;
	std::cout << "data :" << data << std::endl; // notice that the address that data is pointing to is the same as the value of p but as decimal
	Data *data2 = Serializer::deserialize(p);
	print_data(data2);
	delete data;
	return (0);
}