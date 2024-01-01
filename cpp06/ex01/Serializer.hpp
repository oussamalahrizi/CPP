#pragma once

#include <iostream>

typedef struct s_Data
{
	std::string name;
	float salary;
	int age;
} Data;

typedef unsigned long uintptr_t;

class Serializer
{
	private:
		Serializer();
		Serializer(const Serializer& other);
	public:
		Serializer& operator=(const Serializer& other);
		~Serializer();
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};
