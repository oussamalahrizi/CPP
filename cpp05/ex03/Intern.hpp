#pragma once 

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
class Intern
{
	public:
		Intern();
		Intern(const Intern& other);
		~Intern();

		Intern& operator=(const Intern& other);

		AForm* makeForm(const std::string &form_name, const std::string& target);
};
